#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Librerias/pila.h"

int menu(){
    int opt;
    printf("\n==================================\n");
    printf(" TRABAJO PRACTICO N° 3: FUNCIONES\n");
    printf("==================================\n\n");
    printf(" 1.Sumar los elementos de una pila (usar variables enteras).\n\n");
    printf(" 2.Contar los elementos de una pila (usar variables enteras).\n\n");
    printf(" 3.Calcular el promedio de los valores de una pila (usar variables).\n\n");
    printf(" 4.Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas).\n\n");
    printf(" 5.Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables enteras, solo pilas).\n\n");
    printf(" 6.Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.\n\n");
    printf(" 7.Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.\n\n");
    printf(" 8.Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.\n\n");
    printf(" 9.Verificar si una pila DADA es capicúa.\n\n");
    printf(" 10.Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.\n\n");
    printf(" 11.Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).\n\n");
    printf(" 12.Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.\n\n");
    printf(" 13.Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos. En caso de empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de tal manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente.\n\n");
    printf(" 14.SALIR\n\n");
    printf("\n ELIJA UNA OPCIÓN: ");
    fflush(stdin);
    scanf("%i", &opt);
    return opt;
}

int main(){
    setlocale(LC_ALL,"");
    Pila main;
    inicpila(&main);
    Pila aux;
    inicpila(&aux);
    Pila ordenada;
    inicpila(&ordenada);
    int opt=0;
    do{
        opt=menu();
        system("cls");
        switch(opt){
        case 1:{
            printf(" 1.Sumar los elementos de una pila (usar variables enteras).\n\n");
            int suma=0;
            Pila origen;
            Pila aux;
            inicpila (&origen);
            inicpila (&aux);

            char opt;
            int valor;
            do{
                printf(" INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            while (!pilavacia(&origen))
            {
                suma=suma+tope(&origen);

                apilar(&aux,desapilar(&origen));
            }
            while(!pilavacia(&aux)){
                apilar(&origen,desapilar(&aux));
            }
            mostrar(&origen);
            printf(" LA SUMA DE LOS VALORES DENTRO DE LA PILA DA: %i \n\n",suma);
            system("pause");
            system("cls");
        }break;
        case 2:{
            printf(" 2.Contar los elementos de una pila (usar variables enteras).\n\n");
            int count=0;
            Pila origen;
            Pila aux;
            inicpila (&origen);
            inicpila (&aux);

            char opt;
            int valor;
            do{
                printf(" INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }while(opt=='Y'||opt=='y');

            while (!pilavacia(&origen)){
                count=count+1;
                apilar(&aux,desapilar(&origen));
            }
            while(!pilavacia(&aux)){
                apilar(&origen,desapilar(&aux));
            }
            mostrar(&origen);
            printf(" LA CANTIDAD DE LOS ELEMENTOS DENTRO DE LA PILA ES: %i \n\n",count);
            system("pause");
            system("cls");
        }break;
        case 3:{
            printf(" 3.Calcular el promedio de los valores de una pila (usar variables).\n\n");
            int amount=0;
            int sum=0;
            int average=0;
            Pila origen;
            Pila aux;
            inicpila (&origen);
            inicpila (&aux);

            char opt;
            int valor;
            do{
                printf(" INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }while(opt=='Y'||opt=='y');

            while (!pilavacia(&origen)){
                sum=sum+tope(&origen);
                amount=amount+1;
                apilar(&aux,desapilar(&origen));
            }
            average=sum/amount;
            while(!pilavacia(&aux)){
                apilar(&origen,desapilar(&aux));
            }
            mostrar(&origen);
            printf(" EL PROMEDIO DE LOS ELEMENTOS DENTRO DE LA PILA DA: %i \n\n",average);
            system("pause");
            system("cls");
        }break;
        case 4:{
            printf(" 4.Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas).\n\n");
            Pila origen;
            Pila aux;
            Pila menor;
            inicpila (&origen);
            inicpila (&aux);
            inicpila (&menor);
            char opt;
            int valor;
            do{
                printf(" INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }while(opt=='Y'||opt=='y');

            printf("PILA ORIGEN\n");
            mostrar(&origen);
            apilar(&menor, desapilar(&origen));
            while(!pilavacia(&origen)){
                if(tope(&origen)<tope(&menor)){
                    apilar(&aux, desapilar(&menor));
                    apilar(&menor, desapilar(&origen));
                }
                else{
                    apilar(&aux, desapilar(&origen));
                }
            }while(!pilavacia(&aux)){
                apilar(&origen, desapilar(&aux));
            }

            printf("PILA ORIGEN\n");
            mostrar(&origen);
            printf("PILA MENOR\n");
            mostrar(&menor);
            system("pause");
            system("cls");
        }break;
        case 5:{
            printf(" 5.Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables enteras, solo pilas).\n\n");
            Pila origen;
            Pila aux;
            Pila user;
            inicpila(&origen);
            inicpila(&aux);
            inicpila(&user);

            apilar(&origen,6);
            apilar(&origen,4);
            apilar(&origen,2);
            apilar(&origen,1);

            printf("PILA ORIGEN\n");
            mostrar(&origen);
            char opt;
            int valor;
            do{
                printf("\n INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&user,valor);
                printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }while(opt=='Y'||opt=='y');

            while (!pilavacia(&origen) && !pilavacia(&user)){
                while (tope(&origen)<tope(&user)){
                    apilar(&aux, desapilar(&origen));
                }
                apilar(&origen, desapilar(&user));
                while(!pilavacia(&aux)){
                    apilar(&origen,desapilar(&aux));
                }
            }
            printf("PILA ORIGEN\n");
            mostrar(&origen);
            system("pause");
            system("cls");
        }break;
        case 6:{
            printf(" 6.Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.\n\n");
            Pila origen;
            Pila ordenada;
            Pila aux;
            Pila menor;
            inicpila (&origen);
            inicpila(&ordenada);
            inicpila (&aux);
            inicpila (&menor);

            char opt;
            int valor;
            do{
                printf(" INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');
            printf(" PILA ORIGINAL");
            mostrar(&origen);
            while (!pilavacia(&origen)){
                apilar(&menor,desapilar(&origen));
                while (!pilavacia(&origen)){
                    if (tope(&origen)>tope(&menor)){
                        apilar(&aux,desapilar(&origen));
                    }else{
                        apilar(&aux,desapilar(&menor));
                        apilar(&menor,desapilar(&origen));
                    }
                }
                apilar(&ordenada, desapilar(&menor));
                while (!pilavacia (&aux)){
                    apilar(&origen, desapilar(&aux));
                }
            }
            printf(" PILA ORDENADA");
            mostrar(&ordenada);
            system("pause");
            system("cls");
        }break;
        case 7:{
            printf(" 7.Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.\n\n");
            Pila pilaOrigen;
            Pila pilaAux;
            inicpila(&pilaOrigen);
            inicpila(&pilaAux);

            int elementoBuscado=0;
            int flag =0;

            apilar(&pilaOrigen, 10);
            apilar(&pilaOrigen, 20);
            apilar(&pilaOrigen, 30);
            apilar(&pilaOrigen, 40);
            apilar(&pilaOrigen, 50);

            mostrar(&pilaOrigen);

            printf("\n INGRESE EL ELEMENTO A BUSCAR: ");
            scanf("%i", &elementoBuscado);

            while(!pilavacia(&pilaOrigen)&&flag==0){
                if(tope(&pilaOrigen)==elementoBuscado){
                    flag=1;
                }
                else{
                    apilar(&pilaAux, desapilar(&pilaOrigen));
                }
            }
            if(flag==1){
                printf("\n ELEMENTO %i FUE ENCONTRADO\n\n", elementoBuscado);
            }
            else{
                printf("\nELEMENTO %i NO FUE ENCONTRADO\n\n", elementoBuscado);
            }
            while(!pilavacia(&pilaAux)){
                apilar(&pilaOrigen, desapilar(&pilaAux));
            }
            system("pause");
            system("cls");
        }break;
        case 8:{
            printf(" 8.Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.\n\n");
            Pila pilaOrigen;
            Pila pilaAux;

            inicpila(&pilaOrigen);
            inicpila(&pilaAux);

            int elementoEliminar;
            int flag=0;

            apilar(&pilaOrigen, 10);
            apilar(&pilaOrigen, 20);
            apilar(&pilaOrigen, 30);
            apilar(&pilaOrigen, 40);
            apilar(&pilaOrigen, 50);
            apilar(&pilaOrigen, 60);

            printf("PILA ORIGEN\n");
            mostrar(&pilaOrigen);
            printf(" INGRESE EL ELEMENTO A ELMINIAR: ");
            fflush(stdin);
            scanf("%i", &elementoEliminar);
            while(!pilavacia(&pilaOrigen)&&flag==0){
                if(tope(&pilaOrigen)==elementoEliminar){
                    desapilar(&pilaOrigen);
                    flag=1;
                }else{
                    apilar(&pilaAux, desapilar(&pilaOrigen));
                }
            }
            if(flag==1){
                printf("\n EL ELEMENTO %i HA SIDO ELIMINADO\n\n",elementoEliminar);
            }
            else{
                printf("\n NO SE ENCONTRO %i EL ELEMENTO A ELIMINAR\n\n",elementoEliminar);
            }
            while(!pilavacia(&pilaAux)){
                apilar(&pilaOrigen, desapilar(&pilaAux));
            }
            printf("PILA ORIGEN\n");
            mostrar(&pilaOrigen);
            system("pause");
            system("cls");
        }break;
        case 9:{
            printf(" 9.Verificar si una pila DADA es capicúa.\n\n");
            Pila pilaOriginal;
            Pila pilaCopia;
            Pila pilaAux;
            inicpila(&pilaOriginal);
            inicpila(&pilaCopia);
            inicpila(&pilaAux);

            apilar(&pilaOriginal, 10);
            apilar(&pilaOriginal, 20);
            apilar(&pilaOriginal, 30);
            apilar(&pilaOriginal, 20);
            apilar(&pilaOriginal, 10);

            printf("PILA ORIGINAL\n");
            mostrar(&pilaOriginal);

            while(!pilavacia(&pilaOriginal)){
                apilar(&pilaCopia, tope(&pilaOriginal));
                apilar(&pilaAux, desapilar(&pilaOriginal));
            }
            while(!pilavacia(&pilaAux)){
                apilar(&pilaOriginal, desapilar(&pilaAux));
            }

            while(!pilavacia(&pilaOriginal)&&!pilavacia(&pilaCopia)&&tope(&pilaOriginal)==tope(&pilaCopia)){
                desapilar(&pilaOriginal);
                desapilar(&pilaCopia);
            }
            if(pilavacia(&pilaOriginal)&&pilavacia(&pilaCopia)){
                printf(" LA PILA ES CAPICUA\n\n");
            }else{
                printf(" PILA NO ES CAPICUA\n\n");
            }
            system("pause");
            system("cls");
        }break;
        case 10:{
            printf(" 10.Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.\n\n");
            Pila pilaA;
            inicpila(&pilaA);
            Pila pilaAuxA;
            inicpila(&pilaAuxA);
            Pila pilaB;
            Pila pilaAuxB;
            inicpila(&pilaB);
            inicpila(&pilaAuxB);
            Pila pilaAuB;
            inicpila(&pilaAuB);

            apilar(&pilaA, 1);
            apilar(&pilaA, 2);
            apilar(&pilaA, 3);

            apilar(&pilaB, 2);
            apilar(&pilaB, 3);
            apilar(&pilaB, 5);
            apilar(&pilaB, 7);

            mostrar(&pilaA);
            mostrar(&pilaB);

            while(!pilavacia(&pilaA)){
                apilar(&pilaAuB, tope(&pilaA));
                apilar(&pilaAuxA, desapilar(&pilaA));
            }
            while(!pilavacia(&pilaAuxA)){
                apilar(&pilaA, desapilar(&pilaAuxA));
            }
            while(!pilavacia(&pilaB)){
                if(tope(&pilaB)==tope(&pilaA)){
                    apilar(&pilaAuxB, desapilar(&pilaB));
                    apilar(&pilaAuxA, desapilar(&pilaA));
                }else{
                    apilar(&pilaAuB, desapilar(&pilaB));
                }
            }
            mostrar(&pilaAuB);
            system("pause");
            system("cls");
        }break;
        case 11:{
            printf(" 11.Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).\n\n");
            Pila ORDENADA1;
            inicpila(&ORDENADA1);
            Pila ORDENADA2;
            inicpila(&ORDENADA2);
            Pila ORDENADAFINAL;
            inicpila(&ORDENADAFINAL);
            Pila ordenadaAux;
            inicpila(&ordenadaAux);

            apilar(&ORDENADA1, 1);
            apilar(&ORDENADA1, 3);
            apilar(&ORDENADA1, 5);
            apilar(&ORDENADA1, 7);
            apilar(&ORDENADA2, 2);
            apilar(&ORDENADA2, 4);
            apilar(&ORDENADA2, 6);
            apilar(&ORDENADA2, 8);
            printf(" ORDENADA 1");
            mostrar(&ORDENADA1);
            printf(" ORDENADA 2");
            mostrar(&ORDENADA2);

            while(!pilavacia(&ORDENADA1)||!pilavacia(&ORDENADA2)){
                apilar(&ordenadaAux, desapilar(&ORDENADA2));
                apilar(&ordenadaAux, desapilar(&ORDENADA1));
            }
            while(!pilavacia(&ordenadaAux)){
                apilar(&ORDENADAFINAL, desapilar(&ordenadaAux));
            }
            printf(" ORDENADA FINAL");
            mostrar(&ORDENADAFINAL);
            system("pause");
            system("cls");
        }break;
        case 12:{
            printf(" 12.Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.\n\n");
            Pila origen;
            inicpila(&origen);
            Pila destino;
            inicpila(&destino);
            Pila aux;
            inicpila(&aux);

            char opt;
            int valor;
            do{
                printf(" INGRESE UN ELEMENTO: ");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }while(opt=='Y'||opt=='y');

            printf("PILA ORIGEN\n");

            mostrar(&origen);
            if(!pilavacia(&origen)){
                apilar(&destino, desapilar(&origen));
                while(!pilavacia(&origen)){
                    while(!pilavacia(&origen)){
                        if(tope(&origen)>tope(&destino)){
                            apilar(&aux, desapilar(&destino));
                            apilar(&destino, desapilar(&origen));
                        }else{
                            apilar(&aux, desapilar(&origen));
                        }
                    }
                    while(!pilavacia(&aux)){
                        apilar (&origen, desapilar(&aux));
                    }
                    if(!pilavacia(&origen)){
                        apilar(&destino, desapilar(&origen));
                    }
                }
            }else{
                printf("\n LA PILA ESTA VACIA\n\n");
            }
            while(!pilavacia(&destino)){
                apilar(&origen,desapilar(&destino));
            }
            printf(" PILA DESTINO\n");
            mostrar(&origen);
            system("pause");
            system("cls");
        }break;
        case 13:{
            printf(" 13.Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos. En caso de empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de tal manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente.\n\n");
            Pila jugadorUno;
            inicpila(&jugadorUno);
            Pila jugadorDos;
            inicpila(&jugadorDos);
            Pila mazo;
            inicpila(&mazo);
            Pila auxUno;
            inicpila(&auxUno);
            Pila auxDos;
            inicpila(&auxDos);

            apilar(&mazo, 0);
            apilar(&mazo, 4);
            apilar(&mazo, 8);
            apilar(&mazo, 12);
            apilar(&mazo, 16);
            apilar(&mazo, 20);
            apilar(&mazo, 24);
            apilar(&mazo, 28);
            apilar(&mazo, 32);
            apilar(&mazo, 36);
            printf(" MAZO\n");
            mostrar(&mazo);

            int sumaUno=0;
            int sumaDos=0;
            int flag=0;

            while(!pilavacia(&mazo)&&flag==0){
                apilar(&jugadorUno, desapilar(&mazo));
                if(pilavacia(&mazo)){
                    flag=1;
                }else{
                    apilar(&jugadorDos, desapilar(&mazo));
                }
            }
            mostrar(&jugadorUno);
            while(!pilavacia(&jugadorUno)){
                sumaUno = sumaUno+tope(&jugadorUno);
                apilar(&auxUno, desapilar(&jugadorUno));
            }
            printf(" JUGADOR UNO SUMA: %i\n", sumaUno);

            mostrar(&jugadorDos);
            while(!pilavacia(&jugadorDos)){
                sumaDos = sumaDos+tope(&jugadorDos);
                apilar(&auxDos, desapilar(&jugadorDos));
            }
            printf(" JUGADOR DOS SUMA: %i\n\n", sumaDos);

            if(sumaUno>=sumaDos){
                printf(" EL JUGADOR UNO GANA LA MANO CON: %i PUNTOS\n\n", sumaUno);
                while(!pilavacia(&auxUno)&&!pilavacia(&auxDos)&&flag==0){
                    apilar(&jugadorUno, desapilar(&auxUno));
                    if(pilavacia(&auxUno)&&pilavacia(&auxDos)){
                        flag=1;
                    }else{
                        apilar(&jugadorUno, desapilar(&auxDos));
                    }
                }
                printf(" CARTAS JUGADOR UNO\n");
                mostrar(&jugadorUno);
            }else{
                printf(" EL JUGADOR DOS GANA LA MANO CON: %i PUNTOS\n\n", sumaDos);
                while(!pilavacia(&auxUno)&&!pilavacia(&auxDos)&&flag==0){
                    apilar(&jugadorDos, desapilar(&auxUno));
                    if(pilavacia(&auxDos)&&pilavacia(&auxDos)){
                        flag=1;
                    }else{
                        apilar(&jugadorDos, desapilar(&auxDos));
                    }
                }
                printf(" CARTAS JUGADOR DOS\n");
                mostrar(&jugadorDos);
            }
            system("pause");
            system("cls");
        }break;
        case 14:{
            printf(" 14.SALIR\n");
            system("pause");
            system("cls");
        }break;
        default:
            printf("\n OPCION INCORRECTA\n\n");
            system("pause");
            system("cls");
            break;
        }
    }while(opt!=14);
    printf("\n FIN DEL PROGRAMA\n\n");
    system("pause");
    return 0;
}
