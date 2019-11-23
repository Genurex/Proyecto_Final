cmake_minimum_required(VERSION 3.14)

project(Proyecto_Final C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

add_executable(Maineoqc En_el_orden_que_creas/Maineoqc.c En_el_orden_que_creas/eoqc.c En_el_orden_que_creas/eoqc.h)
add_executable(Maintrcp Tan_rapido_como_puedas/Maintrcp.c Tan_rapido_como_puedas/trcp.c Tan_rapido_como_puedas/trcp.h)
add_executable(Maintcp Tantas_como_puedas/Maintcp.c Tantas_como_puedas/tcp.c Tantas_como_puedas/tcp.h)