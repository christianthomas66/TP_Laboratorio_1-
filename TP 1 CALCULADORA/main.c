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
    int flag2 = 0;
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
            fflush(stdin);
            scanf("%c", &opcion);
            opcion = tolower(opcion);


            switch(opcion)
            {
            case 'a':

                printf("Ingrese el 1er operando: \n");
                fflush(stdin);
                scanf("%d", &valorA);
                flag1 = 1;
                break;
            case 'b':
                if(flag1)
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
                if(flag2 && flag1)
                    {
                        printf("Operaciones calculadas con exito\n");
                        suma = sumar(valorA, valorB);
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
                if(flag3)
                    {
                        printf("La suma es: %d\n", suma);
                        printf("La resta es: %d\n", resta);
                        if(valorB == 0)
                        {
                            printf("no se puede dividir por cero\n");
                        }
                        else
                        {
                            printf("La division es: %.2f\n", division);
                        }
                        printf("La multiplicacion es: %d\n", multiplicacion);

                        if(valorA < 0 && valorB < 0)
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
                while(aux != 's' && aux != 'n')
                    {
                        printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                        printf(" s/n : \n");
                        fflush(stdin);
                        scanf("%c", &aux);
                    }

                if(aux == 's')
                    {
                        printf("Gracias. Vuelva pronto!!!\n");
                        return 0;
                    }
                break;
            default:
                fflush(stdin);
                printf("Opcion incorrecta. Reingrese\n");

            }
            system("pause");
            system("cls");



    }while(seguir == 's');

    return 0;
}
