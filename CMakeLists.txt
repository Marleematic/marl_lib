cmake_minimum_required(VERSION 3.13)

project(marl_lib C)


find_package(SDL2)

if (!SDL2_FOUND)
	message(FATAL_ERROR "SDL2 was not found!")
endif()

set(MARL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MARL_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

set(MARL_HEADER_FILES ${MARL_INCLUDE_DIR}/marl.h)
set(MARL_SOURCE_FILES ${MARL_SOURCE_DIR}/marl.c)

add_library(marl_lib SHARED ${MARL_HEADER_FILES} ${MARL_SOURCE_FILES})
target_include_directories(marl_lib PRIVATE ${MARL_INCLUDE_DIR})
target_link_libraries(marl_lib SDL2::SDL2)
