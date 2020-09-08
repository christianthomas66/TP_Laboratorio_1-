#include "Funciones.h"

int sumar(int num1, int num2)
{
    return num1+num2;
}

int restar(int num1, int num2)
{
    return num1-num2;
}
float dividir(int num1, int num2)
{
    return num1/num2;
}

int multiplicar(int num1, int num2)
{
    return num1*num2;
}

int factorial(int num1)
{
    int resultado = 1;

    for(int i = 1; i<= num1; i++)
        {
            resultado = resultado*i;
        }
    return resultado;
}
