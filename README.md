# Sid Meier’s Civilization 5: Scripthook
It turned out that writing mods using the official CIV5 modding SDK is hard when multiplayer should be supported.   
For this reason, we were looking for an easier alternative.

## How it works
It seems CIV5 uses an almost unmodified version of Lua 5.1.4. So all we need to do is to replace the Lua DLL with another self-compiled Lua DLL that shares the same DLL interface. Also, since it's a plain old C library, we don't have to care much about compiler compatibility either.

## Building
1. Create the Visual Studio projects
    ```shell
    > create-projects.bat
    ```
2. Open the solution file located at `build/civ5_scripthook.sln`.
3. Compile the solution and you're done!

## Installation
Copy the `lua51_Win32.dll` from the `bin` folder to your CIV5 root directory (normally `<SteamLibrary>/steamapps/common/Sid Meier's Civilization V/`).   
That's it!
