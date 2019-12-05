//
// Created by user on 5/12/2019.
//
#include "libreria.h"

menu = 1;
menu2 = 1;
menu3 = 1;
t=30;
ch;
puntos=0;
int main(){
    do{
        system("cls");
        presentacion();
        printf("1.Jugar\n");
        printf("2.Ayuda\n");
        printf("3.Salir\n");
        printf("Eleccion: ");
        scanf("%d",&menu);
        while(menu<=0 || menu>=4){
            system("cls");
            presentacion();
            printf("\n\nDebe de introducir una tecla del 1 al 3\n");
            printf("1.Jugar\n");
            printf("2.Ayuda\n");
            printf("3.Salir\n");
            printf("Eleccion: ");
            scanf("%d",&menu);
        }
        if(menu==1){
            system("cls");
            printf(".................................\n");
            printf("Selecciona el que quieras jugar\n");
            printf(".................................\n");
            printf("\n1.TypeSpeed\n");
            printf("2.OrderWord\n");
            printf("3.Atras\n");
            printf("Eleccion: ");
            scanf("%d",&menu2);
            while(menu2<=0 || menu2>=4){
                system("cls");
                printf("\nDebe de introducir una tecla del 1 al 3\n");
                printf(".................................\n");
                printf("Selecciona el que quieras jugar\n");
                printf(".................................\n");
                printf("\n1.TypeSpeed\n");
                printf("2.OrderWord\n");
                printf("3.Atras\n");
                printf("Eleccion: ");
                scanf("%d",&menu2);
            }
            if(menu2==1){
                main_typespeed();
            }
            if(menu2==2){
                main_orderword();
            }
            if(menu2==3){
                menu=1;
            }
        }
        if(menu==2){
            informacion();
        }
        if(menu==3){
            menu = 4;
        }
    }while(menu<=3);
    system("cls");
    printf("\nGracias por jugar\n\n\n");
}
