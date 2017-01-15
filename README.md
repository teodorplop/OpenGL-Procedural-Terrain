# OpenGL 3D Procedural Terrain Generation

OpenGL procedural terrain generation engine, using Perlin Noise to generate Height Maps, which are then processed in order to generate the terrain mesh. A simple water shader with a DUDV texture, which renders on a quad at height zero to make it look pretty.

It includes a console where you can type a few commands that change the terrain in real time.

### Available commands

* help -> Prints a list of avaiable commands.
* set_seed_x -> Sets the seed used to generate Perlin Noise to x.
* set_heightMapRes_x -> Sets the height map texture resolution to x * x.
* set_octaves_x -> Sets the number of octaves from Perlin Noise to x.
* set_amplitude_x -> Sets the amplitudine from Perlin Noise to x.
* set_persistence_x -> Sets the persistence from Perlin Noise to x.
* set_smooth_x -> Sets the smoothness from Perlin Noise to x.
* set_terrainSize_x -> Sets the length and width of the terrain to x.
* set_water_on -> Enables water.
* set_water_off -> Disables water.

### Importing

The project was developed in Microsoft Visual Studio Community 2015, and it can be easily imported as all dependencies are already added here. Libraries added will work for Debug x64.

### References

[OpenGL Step by Step](http://ogldev.atspace.co.uk/)

[ThinMatrix Beginners OpenGL 3D Game Tutorials](https://www.youtube.com/watch?v=VS8wlS9hF8E&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP)

[ThinMatrix OpenGL Water Tutorials](https://www.youtube.com/watch?v=HusvGeEDU_U&list=PLRIWtICgwaX23jiqVByUs0bqhnalNTNZh)

### Dependencies

[freeglut](http://freeglut.sourceforge.net/)

[glew](http://glew.sourceforge.net/)

[GLFW](http://www.glfw.org/)

[FreeImage](http://freeimage.sourceforge.net/)
