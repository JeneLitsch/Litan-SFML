cmake_minimum_required(VERSION 3.13)
project(TPITS)

include_directories(
	./libs/api
	./src
)

set(CMAKE_CXX_STANDARD 20)

add_library(ltnsfml SHARED)

add_subdirectory(src)

target_link_libraries(ltnsfml
	pthread
)

target_link_libraries(ltnsfml
	sfml-graphics
	sfml-audio
	sfml-network
	sfml-system
	sfml-window
)
