//
// Created by user on 22/11/2019.
//

#include "trcp.h"

int fila_azar;

void llenar_matriz_vacia(char matriz[F][C]){
    int i,j;
    for(i=0;i<F;i++){
        for(j=0;j<C;j++){
            matriz[i][j]=' ';
        }
    }
}
void imprimir_matriz(char matriz[F][C]){
    int i,j;
    for(i=0;i<F;i++){
        for(j=0;j<C;j++){
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
}
void insertar(char matriz[F][C], char palabra[10]){
    srand(time(NULL));
    int fila_azar = rand () % ((F-1)-0+1) + 0;
    int tamano = strlen(palabra);
    while(tamano>=0){
        matriz[fila_azar][tamano]=palabra[tamano];
        tamano--;
    }
}
void mover(char matriz[F][C]){
    int i,j=C;
    char tmp;
    int dur = 60;
    while(matriz[fila_azar][C-1]==' '){
        for(i=0;i<F;i++){
            for(j;j>=0;j--){
                tmp=matriz[i][j+1];
                matriz[i][j+1]=matriz[i][j];
                matriz[i][j]=tmp;
            }
            j=C;
        }
        imprimir_matriz(matriz);
        Sleep(dur);
        system("cls");
    }
}