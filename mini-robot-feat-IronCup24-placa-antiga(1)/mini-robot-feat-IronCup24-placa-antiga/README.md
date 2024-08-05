# mini-sumo

## Getting started

- Install [VSCode](https://code.visualstudio.com/download).
- Install [ArduinoIDE](https://www.arduino.cc/en/software).
- Install [PlatformIO Core with CLI](https://platformio.org/install/cli).
- Install [PlatformIO VSCode extension](https://platformio.org/install/ide?install=vscode).
- Set ArduinoIDE Sketchbook directory to the repository root directory.

## Windows

- Install [Python](https://www.python.org/downloads/).
- Create Virtual Environment:

``` 
python -m venv venv
```

- Activate the Virtual Environment by configuring the VSCode Python version or by running:

``` 
venv/Scripts/Activate.ps1
```

- Install PlatformIO package:

```
pip install -U platformio
```

- Check if installation was successfull by running:

```
pio --version
```

The output should be something like:
```
PlatformIO Core, version 6.1.5
```

## Local testing

- Open a new terminal on the repository folder.
- Run:

``` 
pio test -e native
```

If it doesn't work on Linux, try:

``` 
export PATH=$PATH:$HOME/.local/bin
pio test -e native
```