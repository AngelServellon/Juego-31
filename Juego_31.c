#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int aleatorio(int cont, int *randusad, int si);
void mostrarpunt(int cont2, char *cartusadusu1, char *cartusadusu2, int puntjug, int cont3, char *cartusadban1, char *cartusadban2, int puntban);
void ganador(int puntjug, int puntban);
int main()
{
    char ncart1[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    char ncart2[] = {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T'};
    int valcart[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    char cartusadusu1[50];
    char cartusadusu2[50];
    char cartusadban1[50];//banquero
    char cartusadban2[50];//banquero
    int randusad[50];
    randusad[0] = 100;
    randusad[1] = 200;
    int puntjug = 0;
    int cont = 1 , cont2 = 0, cont3 = 0, puntban = 0, random =0, contcart = 0;
    int i, j = 0, k, si = 1;
    int o = 0; 
    int p, q, r;
    char mas, conti; 
    
    do{
        system("cls");
        printf("\n    -------------- BIENVENIDO AL JUEGO 31 --------------\n\n");
        printf("                        SIMBOLOGIA:");
        printf("\n\n                A = AS          E = Espadas\n");
        printf("                J = Principe    C = Corazones\n");
        printf("                Q = Reina       R = Rombos\n");
        printf("                K = Rey         T = Treboles\n\n");
        printf("    ----------------------------------------------------\n\n");
        printf("                        JUGADOR\n\n");
        printf("    Sus primeras 3 cartas son : \n\n");
        srand(time(NULL));
    
        //--------------------------------------------PARTE DEL JUGADOR-------------------------------------
        for(i=0; i<3; i++){
            random = aleatorio(cont, randusad, si);
            
            //printf("\n%d", random);
            cont++;
            cont2++;
            randusad[cont] = random;
            if(valcart[random] == 11){
                printf("\n    Has recibido un AS, digite 1 u 11 para asignarle uno de ");
                printf("\n    esos valores: ");
                scanf("%d", &valcart[random]);       
                printf("\n");
            }
            puntjug += valcart[random];
            printf("    %c%c\n", ncart1[random], ncart2[random]);
            cartusadusu1[cont2] = ncart1[random];
            cartusadusu2[cont2] = ncart2[random];
        
        }
   
        //PEDIR MAS CARTAS
        while(puntjug < 31){
            fflush(stdin);
            printf("\n    Desea otra carta? Ingrese 's' para si o 'n' para no. ");
            scanf("%c", &mas);
            fflush(stdin);
            if(mas == 's' || mas =='S'){
                random = aleatorio(cont, randusad, si);
            
                cont++;
                cont2++;
                contcart++; //contar cartas solicitadas /*agreg*/
                randusad[cont] = random;
                if(valcart[random] == 11){
                    printf("\n    Has recibido un AS, digite 1 u 11 para asignarle uno de ");
                    printf("\n    esos valores: "); 
                    scanf("%d", &valcart[random]);                  
                }
                puntjug += valcart[random];
                printf("\n    %c%c\n", ncart1[random], ncart2[random]);
                cartusadusu1[cont2] = ncart1[random];
                cartusadusu2[cont2] = ncart2[random];
                if(puntjug == 31){
                    printf("\n    Alcanzo la cantidad de 31 puntos");
                    printf("\n\n    USTED ES EL GANADOR. FELICIDADES!!!!!");
                    break;
			            }else if(puntjug > 31){
				              printf("\n    Sobrepaso la cantidad de 31 puntos");
            	       printf("\n\n    USTED PIERDE. SUERTE PARA LA PROXIMA :(");
                    break;
			            }
            }else if(mas == 'n' || mas == 'N'){
                break;
            }
        }
    
        //--------------------------------------------PARTE DEL BANQUERO-------------------------------------
        printf("\n\n     ----------------------------------------------------");
        printf("\n\n                        BANQUERO \n\n");
        printf("    Primeras tres cartas: \n\n");
        for(i=0; i<3; i++){
            random = aleatorio(cont, randusad, si);
            
            cont++;
            cont3++;
            randusad[cont] = random;
            puntban += valcart[random];
            printf("    %c%c\n", ncart1[random], ncart2[random]);
            cartusadban1[cont3] = ncart1[random];
            cartusadban2[cont3] = ncart2[random];
        }
    
        //DAR MAS CARTAS AL BAQUERO
        printf("\n    Cartas adicionales:\n ");
        while(o < contcart){
            if(puntban == 31){
                printf("\n\n    El banquero alcanzó los 31 puntos.");
                printf("\n\n    EL BANQUERO GANA!!!!!");
                break;
            }else if(puntban > 20){
                break;
            }
            random = aleatorio(cont, randusad, si);
            
            cont++;
            cont3++;
            randusad[cont] = random;
            puntban += valcart[random];
            printf("\n    %c%c", ncart1[random], ncart2[random]);
            cartusadban1[cont3] = ncart1[random];
            cartusadban2[cont3] = ncart2[random];
            o++;
        
        }
        if(puntban > 31){
            printf("\n\n    El banquero sobrepaso los 31 puntos.");
            printf("\n\n    EL BANQUERO PIERDE.");
        }
        getch();
        system("cls");
    
        //MOSTRAR PUNTAJE
        mostrarpunt(cont2, cartusadusu1, cartusadusu2, puntjug, cont3, cartusadban1, cartusadban2, puntban);
        
        //RESULTADOS
        ganador(puntjug, puntban);
        getch();
    
        //VACIAR VARIABLES 
        for(r=2; r<=cont; r++){
            randusad[r] = 0;
        }
        for(r=1; r<=cont2; r++){
            cartusadusu1[r] = ' ';
            cartusadusu2[r] = ' ';
        }
        for(r=1; r<=cont3; r++){
            cartusadban1[r] = ' ';
            cartusadban2[r] = ' ';
        }
        valcart[0] = 11;
        valcart[12] = 11;
        valcart[24] = 11;
        valcart[36] = 11;
        puntjug = 0;
        puntban = 0;
        cont = 1;
        cont2 = 0;
        cont3 = 0;
        contcart = 0;
        random = 0;
        o = 0;
        si = 1;
    
        //PREGUNTAR SI DESEA JUGAR DE NUEVO
        printf("\n\n    Deseas jugar de nuevo? Presiona 's' para si o 'n' para no. ");
        scanf(" %c", &conti);
    }while(conti=='s' || conti=='S');
    if(conti == 'n'  || conti == 'N'){
        printf("\n\n    ----------------------------------------------------");
        printf("\n\n                        FIN DEL JUEGO\n\n");
    }
    return 0;
}

//CREAR NÚMERO ALEATORIO
int aleatorio(int cont, int *randusad, int si){
    int j, rando;
    do{
        rando = rand() % 48;
        for(j=0; j<=cont; j++){
            if(rando == randusad[j]){
                si=0;
                break;
            }else{
                si=1;
            }
        }
    } while(si == 0);
    return rando;
}

//MOSTRAR PUNTAJE
void mostrarpunt(int cont2, char *cartusadusu1, char *cartusadusu2, int puntjug, int cont3, char *cartusadban1, char *cartusadban2, int puntban){
    int p, q;
    printf("\n    ----------------------------------------------------\n\n");
    printf("                      PUNTAJE FINAL\n");
    printf("\n    ----------------------------------------------------\n\n");
    printf("                        JUGADOR\n\n");
    printf("    Cartas: ");
    for(p=1; p<=cont2; p++){
        printf("%c%c ", cartusadusu1[p], cartusadusu2[p]);
    }
    printf("\n\n    Puntaje: %d", puntjug);
    printf("\n\n    ----------------------------------------------------\n\n");
    printf("                        BANQUERO\n\n");
    printf("    Cartas: ");
    for(q=1; q<=cont3; q++){
       printf("%c%c ", cartusadban1[q], cartusadban2[q]);
    }
    printf("\n\n    Puntaje: %d", puntban);
    
}

//RESULTADOS
void ganador(int puntjug, int puntban){
    printf("\n\n    ----------------------------------------------------\n\n");
    if((puntjug > puntban) && (puntjug <= 31)){
        printf("                    GANADOR - JUGADOR");
    }else if((puntban > puntjug) && (puntban <= 31)){
        printf("                    GANADOR - BANQUERO");
    }else if(puntjug > 31){
        printf("                    GANADOR - BANQUERO");
    }else if(puntban > 31){
        printf("                    GANADOR - JUGADOR");
    }else if((puntjug == puntban) && (puntjug <= 31) && (puntban <= 31)){
        printf("                    AMBOS JUGADORES EMPATAN");
    }else if((puntjug > 31) && (puntban > 31)){
        printf("                    AMBOS JUGADORES PIERDEN");
    }
    printf("\n\n");
    printf("                    GRACIAS POR JUGAR :)");
}