//
// Created by user on 5/12/2019.
//

#ifndef PROYECTO_FINAL_LIBRERIA_H
#define PROYECTO_FINAL_LIBRERIA_H\

#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>

int menu;
int menu2;
int menu3;
int t;
int ch;
char name[15];
int puntos;

void main_typespeed();
void iniciar_typespeed();
void guardar_puntuacion_typespeed(int puntos,int palabras_por_minuto,int nivel);
void modificar_tiempo_typespeed();
void mostar_puntuacion_typespeed();
int comprobar_palabra(const char* cat,char* input);
char * desordenar_palabra(const char * palabra);
void guardar_puntuacion_orderword(int puntos);
void mostar_puntuacion_orderword();
void informacion();
const char * eleccion(int opc);
void presentacion();
#endif //PROYECTO_FINAL_LIBRERIA_H
