//
// Created by user on 22/11/2019.
//

#include <stdio.h>

#include "eoqc.h"

int main(void){

    char * usuario;
    int opc;
    const char *cat;
    char *newpal;


    printf("Bienvenido a En el orden que creas!\n");
    printf("Somos bien amables, por lo que podras elegir tu categoria\n");
    printf("1.Animales\n2.Superheros\n3.Fundamentos de programacion (categoria valida hasta enero 2020)\n4.prendas\n");

    scanf("%d",&opc);

    while (opc <=0 || opc>=5) {

        printf("Hey, esa no es una categoria, elige de nuevo");
        scanf("%d",&opc);

    }

        while (1) {

            cat = eleccion(opc);

            printf("Llego el momento, digita tu acierto\n");

            printf("%s\n", desordenar_palabra(cat));
            scanf("%s", usuario);


            if(comprobar_palabra(cat, usuario)==1){
                printf("Sigue asi...\n");
            } else{
                break;
            }
        }
    guardar_puntuacion_order_word(score);
    mostar_puntuacion_orderword();






}
