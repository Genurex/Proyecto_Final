//
// Created by user on 22/11/2019.
//

#ifndef PROYECTO_FINAL_EOQC_H
#define PROYECTO_FINAL_EOQC_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int score;

const char* palabraleatoria(const char** cat);
char*desordenar_palabra(const char* pal);
const char * eleccion(int opc);
int comprobar_palabra(const char* cat,char* input);
void guardar_puntuacion_word(int puntos);
void mostar_puntuacion_word();

#endif //PROYECTO_FINAL_EOQC_H
