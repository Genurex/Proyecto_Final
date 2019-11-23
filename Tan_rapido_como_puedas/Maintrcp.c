//
// Created by user on 22/11/2019.
//

#include "trcp.h"

int main(void){
    char matriz[F][C];
    char palabra[10]="sello";
    llenar_matriz_vacia(matriz);
    imprimir_matriz(matriz);
    system("cls");
    insertar(matriz,palabra);
    mover(matriz);
}