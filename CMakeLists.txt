CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(ENCA)

include_directories(include)

aux_source_directory(src/WBMatrix ENCA_SRC)
aux_source_directory(src ENCA_SRC)

add_library(ENCA_LIB ${ENCA_SRC})

add_executable(ENCA test/main.c)

target_link_libraries(ENCA ENCA_LIB m)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O2")