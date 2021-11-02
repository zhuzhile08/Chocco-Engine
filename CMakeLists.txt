# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
# CMakeLists.txt
cmake_minimum_required(VERSION 3.8)
project(ChoccoEngine VERSION 0.1.0)

# set default to debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

set(BIN_DIR ${CMAKE_SOURCE_DIR}/out/build)

# directories for the config files
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(SDL2_image_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(SDL2_ttf_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(SDL2_mixer_DIR ${CMAKE_SOURCE_DIR}/cmake)

# find path to libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# set include directories 
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

# make the executable and link the libraries
add_executable(ChoccoEngine src/main.cpp 
src/ChoccoEngine/init/SDL_init.cpp 
src/ChoccoEngine/init/IMG_init.cpp 
src/ChoccoEngine/init/TTF_init.cpp 
src/ChoccoEngine/init/MIX_init.cpp 
src/ChoccoENgine/init/initALL.cpp 
src/ChoccoEngine/util/SDL_Error.cpp 
src/ChoccoEngine/util/loaders.cpp 
src/ChoccoEngine/util/math.cpp 

)
target_link_libraries(ChoccoEngine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
