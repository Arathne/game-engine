#### see uml
## game engine
#### dependencies -- use ubuntu on windows w/ xming server
```console
$ sudo apt-get install pkg-config cmake libsdl2-dev libsdl2-image-dev g++
$ git submodule update --init
```
#### compile
```console
$ make
$ make run
```
## challenges
#### Uses C++, SDL2, cmake/make
#### The main goal of this game engine is to seperate the rendering from everything else. Focusing less on SDL2 and more on the game itself. To do this, sprites/textures/ and background image need to be loaded into the Workspace. Then the game renderer will take objects from there to draw the images.
#### Collision detection hasn't been implemented yet, but it is possible by having a class that uses the sprites in the explorer to detect any collisions. Fairly easy to implement with the current design.
#### When a texture is loaded or deleted from the workspace, the GameRenderer will be able to detect it. Then it will load the actual texture into the gpu. Each texture and sprite has a unique id. Other classes can have an id to a texture and the GameRenderer will then link them together when drawing.
#### keyboard inputs are handled by the event class with an array that keeps track of current button presses. (same way Andy taught us)
#### look at the main.cpp to get an idea of how development would look like
#### when running the program, use WASD to move. big image in the back is a static unchanging map and small image is a sprite that has velocity
#### I'm planning to change the Tile class since the sprite class should handle position instead of the tile class. Once I fix that, I can add sprites with animations.
#### I think it's cool and will be willing to negotiate a B. The hard part is done, the rest should be much faster to implement.
