# Autoclicker
Command line autoclicker program for minecraft using CMake. Windows only because it uses the winuser sendinput function.
## How to use:
#### Changing the bind key
1. In the `while (true)` loop change whatever is in the parenthesis of `GetAsyncKeyState()`
2. Ex. `GetAsyncKeyState('X')` to change the bind to the X key.
3. Same steps to changing the safety key, which is F4.
#### Max CPS: 
The maximum amount of clicks per second possible
#### Min CPS: 
The minimum amount of clicks per second possible
#### Double click chance: 
The chance for a double click to happen. From 0-100. Effect is applied after each click so a max cps of 10 and double click chance of 100 can go near 20 cps.
#### Click Fail chance: 
The chance for a click to not go through at all. From 0-100
### Fatigue:
Real Humans can't click consistently for long periods of time and can get tired. This can simulate that.
#### Fatigue rate:
The amount of delay to add for each click. If the autoclicker clicks 100 times and this option is at 0.1, The added delay would be 10ms.
#### Max fatigue delay:
The maximum amount of delay the fatigue option can add to each click.
#### Fatigue recovery rate:
The speed at which to recover stamina. It is recommended to set this to double the fatigue rate.
### Safety button:
The safety is to allow the user to press the autoclick key and not trigger the autoclicker. A message will appear in the console notifying if the safety has been turned on or off. The default safety key is F4.
## How to build:
1. Download the source files.
2. Use CMake to make the source files for your preferred compiler.
### Example build instructions for GCC:
1. Use Command prompt and `cd` into the directory
2. Run the command `cmake -G "MinGW Makefiles"` and wait for it to complete
3. Run the command `mingw32-make` or `cmake --build ./` and an .exe will appear.
### Example build instructions for Visual Studio:
1. Use Command prompt and `cd` into the directory
2. Run the command `cmake ./`(because visual studio should be the default generator) or `cmake -G "Visual Studio 17 2022"` and wait for it to complete
3. Open the project file in Visual Studio.
## Tips on how to bypass screenshares
1. Rename the program to windows files but not exactly like ScvHost.exe or cssrs.exe
2. Put the file deep into windows files
3. Put the directory to the autoclicker into PATH
4. Open a new command prompt and just type in the name of the autoclicker
