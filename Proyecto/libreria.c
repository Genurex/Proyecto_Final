//
// Created by user on 5/12/2019.
//
#include "libreria.h"
void main_typespeed(){
    system("cls");
    printf("\nBienvenido a TypeSpeed\n");
    printf(".......................\n");
    printf("Nombre del jugador:");
    scanf("%s",name);

    do{
        system("cls");
        printf("\n.......................\n");
        printf("         MENU\n");
        printf(".......................\n");
        printf("1.Jugar\n");
        printf("2.Tabla de puntuaciones\n");
        printf("3.Establecer limite de tiempo:\n");
        printf("4.Salir\n");
        printf("Seleccion: ");
        scanf("%d",&menu3);
        while(menu3<=0 || menu3>=5){
            system("cls");
            printf("Debe de introducir una tecla del 1 al 4\n");
            printf("1.Jugar\n");
            printf("2.Tabla de puntuaciones\n");
            printf("3.Establecer limite de tiempo:\n");
            printf("4.Salir\n");
            printf("Seleccion: ");
            scanf("%d",&menu3);
        }
        if(menu3==1){
            iniciar_typespeed();
        }
        if(menu3==2){
            mostar_puntuacion_typespeed();
        }
        if(menu3==3){
            modificar_tiempo_typespeed();
        }
        if(menu3==4){
            menu2 = 1;
        }
    }while(menu3<=3);
    menu2 = 1;
}
void iniciar_typespeed(){
    int puntos=0,nivel=1,mode=100,count=0;
    clock_t begin;

    int time_spent=1,palabras_por_minuto=0;

    int r,letter,ch;

    system("cls");
    srand(time(NULL));

    printf("Seleccione el modo\n");
    printf(".......................\n");
    printf("1.Facil (letras minusculas)\n");
    printf("2.Normal (letras mayusculas)\n");
    printf("3.Dificil(letras con caracteres especiales)\n");
    printf("4.Volver al menu\n");
    scanf("%d",&nivel);
    if(nivel==4){
        menu3=1;
    }
    else{
        if(nivel==1)
            mode=97;
        if(nivel==2)
            mode=65;
        if(nivel==3)
            mode=120;
        begin=clock();
        while(1){
            system("cls");
            time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

            if(time_spent>=t){
                break;
            }

            r=rand()%1000;
            r=r%26+mode;
            printf("....Escribe el siguiente caracter....\n\n");
            printf("                %c\n",r); //prints random character

            letter=getch();

            if(letter==r){
                count++;
                puntos=puntos+10;
            }else{
                break;
            }
        }
        palabras_por_minuto=(count*60)/time_spent ;

        if(time_spent<t-1){
            printf("\nHas perdido, juego terminado\n");
        }else{
            printf("\nSe acabo el tiempo, juego terminado\n");
            if((palabras_por_minuto>=40)&&(palabras_por_minuto<=50)){
                printf("\nBien jugado\n");
            }else if(palabras_por_minuto>50){
                printf("\nExcelente!!\n");
            }else{
                printf("Lo sentimos, necesita practica\n");
            }
        }
        printf("Puntos totales: %d\n",puntos);
        printf("Velocidad: %d letra(s) por minuto\n\n",palabras_por_minuto);


        guardar_puntuacion_typespeed(puntos,palabras_por_minuto,nivel);


        printf("1.Volver a jugar\n");
        printf("2.Menu\n");
        printf("3.Salir\n");
        printf("Seleccion:");
        scanf("%d",&ch);
        while(ch<=0 || ch>=4){
            system("cls");
            printf("\nSeleccion equivocada!\n");
            printf("1.Volver a jugar\n");
            printf("2.Menu\n");
            printf("3.Salir\n");
            printf("Seleccion:");
            scanf("%d",&ch);
        }
        if(ch==1){
            iniciar_typespeed();
        }
        if(ch==2){
            menu3 = 1;
        }
        if(ch==3){
            menu = 6;
        }
    }
}
void guardar_puntuacion_typespeed(int puntos,int palabras_por_minuto,int nivel){
    FILE *fp;
    fp=fopen("punt_typespeed.txt","a");
    if(fp==NULL){
        printf("Error");
    }else{
        fprintf(fp,"\nNombre:%s   Puntos=%d    Velocidad=%d    Nivel=%d",name,puntos,palabras_por_minuto,nivel);
    }
    fclose(fp);
}
void modificar_tiempo_typespeed(){
    int ch;
    system("cls");

    printf("Establecer el límite de tiempo para el juego en minutos:");
    printf(".......................\n");
    printf("presione 0 por medio minuto\n");
    printf("presione 1 por 1 minuto\n");
    printf("presione 2 por 2 minutos\n");
    scanf("%d",&ch);
    if(ch==0){
        t=30;
    }else if(ch==1){
        t=60;
    }else if(ch==2){
        t=120;
    }else{
        menu2 = 1;
    }
}
void mostar_puntuacion_typespeed(){
    int ch;
    FILE *fp;
    system("cls");
    printf("....Puntuaciones TypeSpeed....\n");

    fp=fopen("punt_typespeed.txt","r");
    while((ch=fgetc(fp))!=EOF){
        printf("%c",ch);
    }
    getch();
    menu2 = 1;
}
void main_orderword(){
    char * usuario;
    int opc;
    const char *cat;
    char *newpal;
    printf("\nBienvenido a OrderWord\n");
    printf(".......................\n");
    printf("Nombre del jugador:");
    gets(name);
    system("cls");
    do{
        printf("Bienvenido a En el orden que creas!\n");
        printf("Somos bien amables, por lo que podras elegir tu categoria\n");
        printf("1.Animales\n2.Superheroes\n3.Fundamentos de programacion (categoria valida hasta enero 2020)\n4.Prendas\n5.Salir\n");
        scanf("%d",&menu2);
        while (menu2 <=0 || menu2>=6) {
            printf("Hey, esa no es una categoria, elige de nuevo");
            scanf("%d",&menu2);
        }
        if(menu2==5){
            menu = 1;
            break;
        }else{
            while(1){
                cat = eleccion(opc);
                printf("Llego el momento, digita tu acierto\n");
                printf("%s", desordenar_palabra(cat));
                scanf("%s", usuario);
                if(comprobar_palabra(cat, usuario)==1){
                    printf("Sigue asi...\n");
                } else{
                    break;
                }
            }
            guardar_puntuacion_orderword(puntos);
            mostar_puntuacion_orderword();
        }
    }while(menu<=4);
    menu2 = 1;
}
int comprobar_palabra(const char* cat,char* input) {
    if(strcmp(cat, input) == 0){
        puntos += 10;
        return 1;
    }
    return 0;
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
void guardar_puntuacion_orderword(int puntos){
    FILE *fp;
    fp=fopen("punt_orderword.txt","a");
    if(fp==NULL){
        printf("Error");
    }else{
        fprintf(fp,"\nNombre:%s   Puntos=%d",name,puntos);
    }
    fclose(fp);
}
void mostar_puntuacion_orderword(){
    int ch;
    FILE *fp;
    system("cls");
    printf("....Puntuaciones de OrderWord....\n");
    fp=fopen("punt_orderword.txt","r");
    while((ch=fgetc(fp))!=EOF){
        printf("%c",ch);
    }
    getch();
}
void informacion(){
    system("cls");
    printf("......Ayuda......\n");
    printf("=  >Ingrese su nombre\n");
    printf("=  >Establezca el limite de tiempo en la opcion 3 en el menu principal (el limite por default es 30 segundos)\n");
    printf("=  >selecciona el nivel y comienza\n");
    printf("=  >Se muestran los caracteres y debe escribirlos lo más rapido posible\n");
    printf("=  >Evite escribir incorrectamente, de lo contrario el juego habrá terminado\n");

    getch();
    menu = 1;
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
    else if(opc == 4){
        const char* prendas[] = {
                "cadena", "anillo", "bufanda",
                "shorts", "jeans", "tshirt",
                "zapatos", "tenis", "pendientes",
                "gafas", "collar", "gorra",
                "poloshirt", "collar", "cinturon",
        };
        categoria = palabraleatoria(prendas);
    }
    return categoria;
}
void presentacion(){
    printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
            ,254,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
            ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
            ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
            ,205,205,205,205,254);

    printf("            __ _____ _____ _____ _____    ____  _____    _____ _____ __    _____ _____ _____ _____ _____\n");
    printf("  |  |  |  |   __|   __|     |  |    \\|   __|  |  _  |  _  |  |  |  _  | __  | __  |  _  |   __|\n");
    printf("  |  |  |  |  |   __|  |  |  |  |  |  |  |   __|  |   __|     |  |__|     | __ -|    -|     |__   |\n");
    printf("  |_____|_____|_____|_____|_____|  |____/|_____|  |__|  |__|__|_____|__|__|_____|__|__|__|__|_____|");
    printf("\n");

    printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
            ,254,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
            ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
            ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205
            ,205,205,205,205,254);
}
