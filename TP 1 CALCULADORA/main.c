#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Funciones.h"


int main()
{
    int valorA;
    int valorB;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorial_1;
    int factorial_2;

    int flag1 = 0;
    int flag2 = 0; // Variables bandera para activar opciones
    int flag3 = 0;

    char seguir = 's';
    char aux;
    char opcion;

    do{
            printf("---------- MENU DE OPCIONES ----------\n");
            printf("A) Ingresar el 1er operando (A=X):\n");
            printf("B) Ingresar el 2do operando (B=Y):\n");
            printf("C) Calcular las operaciones:\n");
            printf(" 1. Calcular Suma (A+B)\n");
            printf(" 2. Calcular Resta (A-B)\n");
            printf(" 3. Calcular Division (A/B)\n");
            printf(" 4. Calcular Multiplicacion (A*B)\n");
            printf(" 5. Calcular Factorial (A!) y (B!)\n");
            printf("D) Informar operaciones: \n");
            printf("E) SALIR\n");
            fflush(stdin);  //Limpio el buffer
            scanf("%c", &opcion);
            opcion = tolower(opcion); // convierto la opcion elegida para que sea ingresada tanto con minuscula como mayuscula


            switch(opcion)  //hago un switch para manejar distintas opciones
            {
            case 'a':

                printf("Ingrese el 1er operando: \n");
                fflush(stdin);
                scanf("%d", &valorA);
                flag1 = 1;
                break;
            case 'b':
                if(flag1) // Si no ingresé el primer operando, esta opcion estará bloqueada y entrará al else de este case
                    {
                        printf("Ingrese el 2do operando: \n");
                        fflush(stdin);
                        scanf("%d", &valorB);
                        flag2 = 1;
                    }

                else
                    {
                        printf("Para ingresar el 2do operando primero debes ingresar el 1ero\n");
                    }

                break;
            case 'c':
                if(flag2 && flag1) // Si no ingresé a las 2 primeras opciones(los operandos) esta opcion estará bloqueada y entrará al else de este case
                    {
                        printf("Operaciones calculadas con exito\n");
                        suma = sumar(valorA, valorB); // llamo a las funciones y les paso los parametros por valor
                        resta = restar(valorA, valorB);
                        division = dividir(valorA, valorB);
                        multiplicacion = multiplicar(valorA, valorB);
                        factorial_1 = factorial(valorA);
                        factorial_2 = factorial(valorB);
                        flag3 = 1;
                    }
                else
                    {
                        printf("Para calcular las operaciones. Primero hay que ingresar los operandos A y B\n\n");
                    }

                break;
            case 'd':
                if(flag3) // Si no entraa ninguna de las opciones(case a,b o c), esta opcion estará bloqueada y entrará al else hasta que no se ingresen los operandos, ni se haya calculado
                    {
                        printf("La suma es: %d\n", suma);
                        printf("La resta es: %d\n", resta);
                        if(valorB == 0) // Si el 2do operando es 0, no se puede realizar una division por 0, y si no, entrará al else y hará una division normal
                        {
                            printf("no se puede dividir por cero\n");
                        }
                        else
                        {
                            printf("La division es: %.2f\n", division);
                        }
                        printf("La multiplicacion es: %d\n", multiplicacion);

                        if(valorA < 0 && valorB < 0) // Si los valores de los operandos son 0 no se puede realizar factorial, caso contrario entrará al else y calculará el factorial normal de ambos operandos
                        {
                            printf("No se puede realizar el factorial de 0\n");
                        }
                        else
                        {
                            printf("El factorial de A es: %d\nEl factorial de B es: %d\n", factorial_1, factorial_2);
                        }
                    }
                    else
                        {
                            printf("Antes de informar los resultados. Primero debes ingresar los operandos A y B, y calcularlos!\n");
                        }

                break;

            case 'e':
                printf("Desea salir???\n");
                fflush(stdin);
                scanf("%c", &aux);
                while(aux != 's' && aux != 'n') // Mientras la opcion de tipo char no sean ni las letras 's' o 'n' la iteracion se ejecutará con el mensaje de manera infinita
                    {
                        printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                        printf(" s/n : \n");
                        fflush(stdin);
                        scanf("%c", &aux);
                    }

                if(aux == 's') // si la opcion es 's' termina el programa
                    {
                        printf("Gracias. Vuelva pronto!!!\n");
                        return 0;
                    }
                break;
            default: // si el usuario ingresa cualquier cosa que no sean las opciones indicadas de los cases, entrará al default y muestra el mensaje
                fflush(stdin);
                printf("Opcion incorrecta. Reingrese\n");

            }
            system("pause");// Tiempo de espera luego de ejecutar una opcion
            system("cls"); // Limpio la pantalla despues de haber ejecutado una opcion



    }while(seguir == 's'); //

    return 0;
}
