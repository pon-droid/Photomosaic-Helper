cmake_minimum_required(VERSION 3.5)

project(ASPECT_RATIO_CONVERTER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ASPECT_RATIO_CONVERTER main.cpp)
add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(ASPECT_RATIO_CONVERTER ${ImageMagick_LIBRARIES})
