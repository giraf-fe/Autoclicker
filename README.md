# Autoclicker
Autoclicker program for minecraft using CMake. Windows only because it uses the winuser sendinput function.
## How to use:
Max CPS: The maximum amount of clicks per second possible
Min CPS: The minimum amount of clicks per second possible
Double click chance: The chance for a double click to happen. From 0-100. Effect is applied after each click so a max cps of 10 and double click chance of 100 can go near 20 cps.
Click Fail chance: The chance for a click to not go through at all. From 0-100
## How to build:
1. Download the source files.
2. Use CMake to make the source files for your preferred compiler.
### Example build instructions for GCC:
1. Use Command prompt and `cd` into the directory
2. Run the command `cmake -G "MinGW Makefiles"` and wait for it to complete
3. Run the command `mingw32-make` and an .exe will appear.
### Example build instructions for Visual Studio:
1. Use Command prompt and `cd` into the directory
2. Run the command `cmake`(because visual studio should be the default generator) and wait for it to complete
3. Open the project file in Visual Studio.
