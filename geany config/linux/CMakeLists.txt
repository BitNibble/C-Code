cmake_minimum_required(VERSION 3.28)

set(CFLAGS -g -Wall -Wextra -Werror)
set(LDFLAGS -lm)
project(out)
set(SOURCE_FILE Test_8.c)
set(SOURCE_DIR ./user_lib/src)

include_directories(usr_lib PUBLIC . ./user_lib/inc)
add_library(usr_lib ${SOURCE_DIR}/circbuffer.c ${SOURCE_DIR}/explode.c ${SOURCE_DIR}/PCficheiro.c ${SOURCE_DIR}/PCfunction.c ${SOURCE_DIR}/PClili.c ${SOURCE_DIR}/procedures.c ${SOURCE_DIR}/poop.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})
target_link_libraries(${PROJECT_NAME} usr_lib ${CFLAGS} ${LDFLAGS} )


