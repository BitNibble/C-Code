cmake_minimum_required(VERSION 3.28)

project(out C)

# Source files
set(SOURCE_FILE Test_8.c)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/user_lib/src)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/user_lib/inc)

# Add user library
add_library(usr_lib
    ${SOURCE_DIR}/circbuffer.c
    ${SOURCE_DIR}/explode.c
    ${SOURCE_DIR}/ostdio.c
    ${SOURCE_DIR}/ostdlib.c
    ${SOURCE_DIR}/ostring.c
    ${SOURCE_DIR}/PCficheiro.c
    ${SOURCE_DIR}/PCfunction.c
    ${SOURCE_DIR}/PClili.c
    ${SOURCE_DIR}/poop.c
    ${SOURCE_DIR}/procedures.c
)

# Add the main executable
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

# Link the executable with the library
target_link_libraries(${PROJECT_NAME} usr_lib m)

# Set compile options
target_compile_options(${PROJECT_NAME} PRIVATE -g -Wall -Wextra -Werror)
