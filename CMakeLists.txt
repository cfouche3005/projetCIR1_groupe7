cmake_minimum_required(VERSION 3.18)
project(projetCIR1_groupe7 C)

set(CMAKE_C_STANDARD 11)

add_executable(projetCIR1_groupe7 C/main.c C/Planete.c C/Trajectoire.c C/Point.c C/Vecteur.c)
target_link_libraries(projetCIR1_groupe7 m)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
