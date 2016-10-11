# OpenGL 3D Procedural Terrain Generation

OpenGL procedural terrain generation engine, using Perlin Noise to generate Height Maps, which are then processed in order to generate the terrain mesh. A simple water shader with a DUDV texture, which renders on a quad at height zero to make it look pretty.

It includes a console where you can type a few commands that change the terrain in real time.

Available commands:

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
