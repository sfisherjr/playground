### playground engine
### Building
#### Windows
1. Install vcpkg from https://github.com/microsoft/vcpkg
2. Run ```vcpkg install sfml:x64-windows```
3. Add the -DCMAKE_TOOLCHAIN_FILE CMake option
4. Run CMake and Build

It's recommended to use the Visual Studio toolchain with architecture set to amd64.
#### Ubuntu
1. Install sfml ```apt install sfml-dev```
2. Run CMake and Build
### Map Files (.gmap)
#### Overview
An example map file is included under the resources directory.

The map file is a text file that holds the tile index from a spritesheet. The example below 
shows the result based on the example spritesheet. 

```
111,186*8,112
160,162*8,161
160,162*8,161
160,162*8,161
137,187*8,138
```
![Imgur](https://i.imgur.com/CEe8jRk.png)
#### Tile Row Expansion
Using ```TileIndex*n``` will cause the tile to be copied to the next ```n``` tiles.

```111,186*8,112```  
This will display the tile at index 186 8 times. 
