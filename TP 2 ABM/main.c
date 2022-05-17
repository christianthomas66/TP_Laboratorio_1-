#include <stdlib.h>
#include "Empleados.h"
#define TAM 1000

int main()
{
    Employee empleados[TAM];
    int opcion;
    int estado;
    int id=100;
    int sector;
    char name[30];
    char lastName[30];
    float salary;
    int baja;
    int modificar;

    initEmployees(empleados, TAM);

    //Employee empleado1[TAM] = {1, "thomas", "suarez", 1000, 1, 2};

    do
    {
        printf("***** MENU DE OPCIONES ABM *****\n\n");
        printf("1) ALTAS \n");
        printf("2) MODIFICAR \n");
        printf("3) BAJA \n");
        printf("4) INFORMAR \n");
        printf("5) SALIR \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1 :
            getInt("ingrese su sector: ","error\n",1,3,10,&sector);
            getName("Ingrese nombre: \n","error\n",4,20,10,name);
            getName("ingrese apellido: \n","error\n",4,20,10,lastName);
            getFloat("ingrese salario: \n","error\n",4,8,10,&salary);

            estado = addEmployee(empleados,TAM,id,name,lastName,salary,sector);
            if(estado == 0)
            {
                printf("se cargo el usuario");
                id++;
            }
            else
            {
                printf("no se cargo el usuario");
            }
            break;

        case 2 :
            if(estado== 0)
            {
                printEmployees(empleados,TAM);
                printf("ingrese id que desea Modificar: \n");
                scanf("%d",&modificar);
                modificar = modificarEmployee(empleados,TAM,modificar);
                if(modificar == 0)
                {
                    printf("se modifico el usuario");
                    id++;
                }
                else
                {
                    printf("no se modifico el usuario");
                }
            }

            else
            {
                printf("usted no ingreso ningun usuario\n");
            }

            break;

        case 3 :
            if (estado == 0)
            {
                printEmployees(empleados,TAM);
                printf("ingrese id que desea dar de baja: \n");
                scanf("%d",&baja);
                baja = removeEmployee(empleados,TAM,baja);
                if (baja == 0)
                {
                    printf("se dio de baja el usuario");
                    id++;
                }
                else
                {
                    printf("no dio de baja el usuario");
                }
            }
            else
            {
                printf("usted no ingreso ningun usuario\n");
            }
            break;

        case 4 :
            if (estado == 0)
            {
                printf("\t*****listado******\n");
                printEmployees (empleados, TAM);
                //printf("empleado1", empleado1);
                printf("*****listado ordenano de manera ascendente******\n");
                sortEmployeeByNameAndAverage(empleados,TAM);
                printEmployees (empleados,TAM);
                printf("*****salarios******\n");
                mostrarSalaryPromedioSuperiorPromedio(empleados,TAM);
            }

            else
            {
                printf("usted no ingreso ningun usuario\n");
            }
            break;


        case 5 :
            printf("usted salio!!!\n");
            break;


        default :
            printf("Opcion incorrecta!!!\n");

        }
        system("pause");
        system("cls");
    }
    while (opcion != 5);
    return 0;
}









