//
// Created by user on 22/11/2019.
//

#include "eoqc.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stddef.h>


const char * eleccion(int opc){

    const char *categoria;

    if (opc == 1){

        const char *animales[] = {
                "ballena", "ornitorrinco", "paloma",
                "caballo", "nutria", "rinoceronte",
                "elefante", "hamster", "camaleon",
                "serpiente", "Medusa", "mariquita",
                "manati", "ajolote", "cangrejo",
        };
        categoria = palabraleatoria(animales);

    }

    else if (opc == 2) {

        const char *superheroes[] = {
                "superman", "batman", "thor",
                "hulk", "x-men", "spiderman",
                "ironman", "deadpool", "iceman",
                "wonderwoman", "flash", "wolverine",
                "doctor strange", "aquaman", "linterna verde",
        };
        categoria = palabraleatoria(superheroes);
    }
    else if (opc == 3) {

        const char *fundamentosp[] = {
                "puntero", "estructura", "archivos",
                "arreglo", "repositorio", "cadenas",
                "uniones", "listas enlazadas", "memoria",
                "minunit", "ordenamiento", "dinamico",
                "portafolio", "ivantactuk", "debug",
        };

        categoria = palabraleatoria(fundamentosp);

    }

    return categoria;


}


const char* palabraleatoria(const char** cat){

    int i;
    int al;

    i = 15;
    al = 0;

    srand((unsigned)time(NULL));
    al = rand() % i;

    return cat[al];
}


char * desordenar_palabra(const char * palabra){

    srand(time(NULL));
    int cant,ind;
    char tmp;

    cant = strlen(palabra)-1;
    char * palabra_modificada= malloc((strlen(palabra)+1)*sizeof(char));
    strcpy(palabra_modificada,palabra);

    for(int i=0;i<cant;i++){
        ind = rand() % cant;
        tmp = palabra_modificada[i];
        palabra_modificada[i] = palabra_modificada[ind];
        palabra_modificada[ind] = tmp;
    }

    return palabra_modificada;
}

int comprobar_palabra(const char* cat,char* input) {

    if (strcmp(cat, input) == 0) {

        score += 10;
        return 1;
    } else {
        printf("and i oop");
        return 0;
    }
}


void guardar_puntuacion_order_word(int puntos){

    FILE *fp;
    fp=fopen("punt_orderword.txt","a");
    if(fp==NULL){
        printf("Error");
    }else{
        fprintf(fp,"\nNombre:%s   Puntos=%d","HH",puntos);
    }
    fclose(fp);
}
void mostar_puntuacion_orderword(){

    int ch;
    FILE *fp;
    system("cls");
    printf("....Puntuaciones de OrderWord...\n");

    fp=fopen("punt_orderword.txt","r");
    while((ch=fgetc(fp))!=EOF){
        printf("%c",ch);
    }
    getch();
   // menu = 1;
}
