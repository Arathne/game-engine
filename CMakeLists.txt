cmake_minimum_required( VERSION 3.16.2 )

project( GameEngine 
         VERSION 1.0 
         DESCRIPTION "simple game engine" 
         LANGUAGES CXX C )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

set(glm_DIR glm/cmake/glm)
find_package(glm REQUIRED)

include(path.cmake)
add_executable( engine ${CPP} )

target_link_libraries( engine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} glm::glm )
target_include_directories( engine PUBLIC ${SDL2_INCLUDE_DIRS} )

target_compile_options( engine PUBLIC ${SDL2_CFLAGS_OTHER} )
target_compile_definitions( engine PRIVATE EPIC_FACE="${CMAKE_CURRENT_SOURCE_DIR}/assets/epicface.png" )
