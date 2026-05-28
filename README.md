# OpenGL 3D Procedural Terrain Generation

A real-time OpenGL procedural terrain generation engine using **Perlin Noise** to generate height maps. Originally built on Windows using Visual Studio, this project has been ported to Linux using cross-platform **CMake** and **C++17**.

## Features

The engine generates realistic terrain meshes procedurally using:
* **Perlin Noise Height Maps** - Multi-octave noise generation with configurable parameters
* **Real-time Console Commands** - Interactive terrain manipulation without recompilation
* **Water Rendering** - Simple water shader with DUDV texture distortion at height zero

### Available Commands

Access the in-game console to modify terrain parameters in real-time:

* **help** - Prints a list of available commands
* **set_seed_x** - Sets the seed used to generate Perlin Noise to `x`
* **set_heightMapRes_x** - Sets the height map texture resolution to `x * x`
* **set_octaves_x** - Sets the number of octaves from Perlin Noise to `x`
* **set_amplitude_x** - Sets the amplitude from Perlin Noise to `x`
* **set_persistence_x** - Sets the persistence from Perlin Noise to `x`
* **set_smooth_x** - Sets the smoothness from Perlin Noise to `x`
* **set_terrainSize_x** - Sets the length and width of the terrain to `x`
* **set_water_on** - Enables water rendering
* **set_water_off** - Disables water rendering

---

## Prerequisites & Dependencies

To compile and run this project on Linux, you will need a C++17 compliant compiler (`gcc` or `clang`), `cmake`, and the following development libraries:

* **OpenGL** (Core Graphics Drivers)
* **GLEW** (Extension Wrangler)
* **GLFW** (Windowing & Input)
* **FreeGLUT** (Utility Toolkit)
* **FreeImage** (Image Loading)

### Dependency Installation

#### CachyOS / Arch Linux
Most libraries are available via the standard package manager (`pacman`). Note that `freeimage` must be installed via the Arch User Repository (AUR) using an AUR helper like `paru` or `yay`.

```bash
# Install core build tools and standard repositories libraries
sudo pacman -S base-devel cmake glew glfw freeglut glm

# Install FreeImage from the AUR (Do NOT run with sudo)
paru -S freeimage
# OR:
yay -S freeimage
```

#### Ubuntu / Debian

If setting up on a Debian-based distribution, use `apt`:

```bash
sudo apt update
sudo apt install build-essential cmake libglew-dev libglfw3-dev freeglut3-dev libfreeimage-dev libglm-dev
```

---

## Building the Project

You can build the project either directly through the terminal or by using Visual Studio Code.

### Method 1: Via Terminal (Standard CMake)

From the project root directory, run the following commands to configure and compile:

```bash
# Create and enter the build directory
mkdir build && cd build

# Configure the project using native Linux compilers
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Compile the executable
make
```

### Method 2: Via VS Code (Recommended)

1. Open the project folder in VS Code.

2. Install the following extensions:
   - **C/C++** (by Microsoft)
   - **CMake Tools** (by Microsoft)

3. Open the Command Palette (`Ctrl + Shift + P`) and run **CMake: Select a Kit**. Choose your native host compiler (e.g., GCC or Clang). Do **NOT** select `clang-cl`.

4. Run **CMake: Configure**.

5. Click the **Build** button on the bottom blue status bar (or press `F7`).

---

## Running the Application

There are two critical platform constraints to keep in mind when running this application on modern Linux systems:

1. **Working Directory**: The application loads assets (Shaders, Textures) using relative paths. It must be executed with the project root folder as the working directory.

2. **Wayland Display Server**: If you are running a Wayland-based desktop (default on CachyOS), GLEW requires an X11 context to initialize properly (`No GLX display` error). You must pass the `GLFW_PLATFORM=x11` environment variable to force XWayland compatibility.

### Running via Terminal

Always run the executable from the project root directory (not from inside the `build` folder):

```bash
# Ensure you are in the project root folder
cd /path/to/OpenGL-Procedural-Terrain

# Launch the app forcing X11 context compatibility
GLFW_PLATFORM=x11 ./build/OpenGL_Procedural_Terrain
```

### Running via VS Code (Automated Setup)

To make clicking the Play **[▷]** button in VS Code work seamlessly without errors, create or update `.vscode/settings.json` in your project root with the following configuration:

```json
{
    "cmake.debugConfig": {
        "cwd": "${workspaceFolder}",
        "environment": [
            {
                "name": "GLFW_PLATFORM",
                "value": "x11"
            }
        ]
    }
}
```

Once saved, clicking **Launch / Play** on the bottom status bar will properly route the assets paths and handle display window contexts automatically.

---

## References

[OpenGL Step by Step](http://ogldev.atspace.co.uk/)

[ThinMatrix Beginners OpenGL 3D Game Tutorials](https://www.youtube.com/watch?v=VS8wlS9hF8E&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP)

[ThinMatrix OpenGL Water Tutorials](https://www.youtube.com/watch?v=HusvGeEDU_U&list=PLRIWtICgwaX23jiqVByUs0bqhnalNTNZh)

## Dependencies

[freeglut](http://freeglut.sourceforge.net/) | [glew](http://glew.sourceforge.net/) | [GLFW](http://www.glfw.org/) | [FreeImage](http://freeimage.sourceforge.net/)
