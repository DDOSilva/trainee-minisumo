#include "strategy.h"

Move::Move(int left_motor_power, int right_motor_power, int time_ms)
{
    this->left_motor_power = left_motor_power;
    this->right_motor_power = right_motor_power;
    this->time_ms = time_ms;
    this->start_time_ms = 0;
    this->started = false;
    this->finished = false;
}

/*
returns true if the move finishes
*/
bool Move::update(MotorControl &left_motor, MotorControl &right_motor)
{
    int delta_time_ms = 0;
    int now_ms = millis();
    if (!this->started)
    {

        this->started = true;
        this->start_time_ms = now_ms;
        left_motor.setPower(this->left_motor_power);
        right_motor.setPower(this->right_motor_power);
        return false;
    }
    else
    {
        delta_time_ms = now_ms - this->start_time_ms;
        if (delta_time_ms >= this->time_ms)
        {
            this->finished = true;
            return true;
        }
        else
        {
            return false;
        }
    }
    char msg[] = "WRONG MOVE LOGIC";
    Serial.println(msg);
    return true;
}

InitialStrategy::InitialStrategy(std::list<Move> moves) : moves(moves), current_move(moves.front())
{
    this->moves.pop_front();
    this->strategy_finished = false;
}

bool InitialStrategy::update(MotorControl &left_motor, MotorControl &right_motor)
{
    if (this->strategy_finished)
    {
        return true;
    }

    bool current_move_finished;
    current_move_finished = this->current_move.update(left_motor, right_motor);

    if (current_move_finished)
    {
        if (this->moves.empty())
        {
            this->strategy_finished = true;
            return true;
        }
        this->current_move = this->moves.front();
        this->moves.pop_front();

        this->current_move.update(left_motor, right_motor);
        return false;
    }
    else
    {
        return false;
    }

    char msg[] = "WRONG INITIAL STRATEGY LOGIC";
    Serial.println(msg);
    return true;
}

void AutoStrategy::updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor)
{
    if(vision.line_position == LinePosition::LEFT_LINE){
        left_motor.setPower(100);
        right_motor.setPower(-100);
        return;
    }
    else if(vision.line_position == LinePosition::RIGHT_LINE){
        left_motor.setPower(-100);
        right_motor.setPower(100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::FRONT)
    {
        left_motor.setPower(100);
        right_motor.setPower(100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::FRONT_LEFT)
    {
        left_motor.setPower(60);
        right_motor.setPower(100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::FRONT_RIGHT)
    {
        left_motor.setPower(100);
        right_motor.setPower(60);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::LEFT)
    {
        left_motor.setPower(40);
        right_motor.setPower(100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::RIGHT)
    {
        left_motor.setPower(100);
        right_motor.setPower(40);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::FULL_RIGHT)
    {
        left_motor.setPower(100);
        right_motor.setPower(-100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::FULL_LEFT)
    {
        left_motor.setPower(-100);
        right_motor.setPower(100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::SEARCH_LEFT)
    {
        left_motor.setPower(15);
        right_motor.setPower(100);
        return;
    }
    else if (vision.enemy_position == EnemyPosition::SEARCH_RIGHT)
    {
        left_motor.setPower(100);
        right_motor.setPower(15);
        return;
    }
}

InitialStrategy *get_selected_strategy(int pinA, int pinB, int pinC)
{
    bool selectA = digitalRead(pinA);
    bool selectB = digitalRead(pinB);
    bool selectC;
    int readC = analogRead(pinC);
    if (readC>3000){
        selectC = true;
        }
    else {
        selectC = false;
        }


    int selected_number = int(selectA) + (int(selectB) << 1) + (int(selectC) << 2);
    InitialStrategy *initial_strategy;
    std::list<Move> moves = {};
    switch (selected_number)
    {
    case 0: // desempate                           00    
        moves.push_back(Move(100, -100, 300));
        break;
    case 1: // direita - frente -esquerda          01                                                                           aaron ajudou a salvar aqui
        moves.push_back(Move(100, 30, 100));
        moves.push_back(Move(100, 100, 80));
        moves.push_back(Move(30, 100, 120));
        break;
    case 2: // frente - esquerda - direita         10   
        moves.push_back(Move(100, 100, 80));
        moves.push_back(Move(30, 100, 120));
        moves.push_back(Move(100, 30, 60));
        break;
    case 3: //frente                               11                                 
        moves.push_back(Move(100, 100, 400));
        break;
    default:
        break;
    }

    initial_strategy = new InitialStrategy(moves);

    return initial_strategy;
}
