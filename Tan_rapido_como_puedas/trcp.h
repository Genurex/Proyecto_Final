//
// Created by user on 22/11/2019.
//

#ifndef PROYECTO_FINAL_TRCP_H
#define PROYECTO_FINAL_TRCP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define F 20
#define C 50

void llenar_matriz_vacia(char matriz[F][C]);
void imprimir_matriz(char matriz[F][C]);
void insertar(char matriz[F][C], char palabra[10]);
void mover(char matriz[F][C]);

#endif //PROYECTO_FINAL_TRCP_H
