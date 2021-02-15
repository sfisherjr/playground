### playground engine
### Building
#### Windows
1. Install vcpkg from https://github.com/microsoft/vcpkg
2. Run ```vcpkg install sfml:x64-windows```
3. Add the -DCMAKE_TOOLCHAIN_FILE CMake option

It's recommended to use the Visual Studio toolchain with architecture set to amd64.
### Map Files (.gmap)
An example map file is included under the resources directory.

The map file is a text file that holds the tile index from a spritesheet. The example below 
shows the result based on the example spritesheet. 

```
111,186,186,186,186,186,186,186,186,186,186,186,186,112
160,162,162,162,162,162,162,162,162,162,162,162,162,161
160,162,162,162,162,162,162,162,162,162,162,162,162,161
160,162,162,162,162,162,162,162,162,162,162,162,162,161
137,187,187,187,187,187,187,187,187,187,187,187,187,138
```
![Imgur](https://i.imgur.com/CEe8jRk.png)