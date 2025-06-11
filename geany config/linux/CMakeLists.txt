cmake_minimum_required(VERSION 3.10)

project(out)

add_executable( out Test_6.c ./user_lib/src/circbuffer.c ./user_lib/src/explode.c ./user_lib/src/PCficheiro.c ./user_lib/src/PCfunction.c ./user_lib/src/PClili.c ./user_lib/inc/explode.h ./user_lib/inc/PCficheiro.h ./user_lib/inc/PCfunction.h ./user_lib/inc/PClili.h )

target_link_libraries(out PRIVATE m)
