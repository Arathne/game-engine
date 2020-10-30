cmake_minimum_required( VERSION 3.16.2 )

project( GameEngine 
         VERSION 1.0 
         DESCRIPTION "simple game engine" 
         LANGUAGES CXX C )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

#include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

set(glm_DIR glm/cmake/glm)
find_package(glm REQUIRED)

add_executable( engine main.cpp GameRenderer.cpp Events.cpp Color.cpp Scene.cpp Workspace.cpp Tile.cpp StaticMap.cpp )

target_link_libraries( engine ${SDL2_LIBRARIES} glm::glm )
target_include_directories( engine PUBLIC ${SDL2_INCLUDE_DIRS} )
target_compile_options( engine PUBLIC ${SDL2_CFLAGS_OTHER} )
