#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    int flagCsv = 0;
    int flagBin = 0;
    char salir[3];
    char aux;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {   strcpy(salir,"no");
        getInt("1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n3) Alta empleado\n4) Modificar empleado\n5) Baja empleado\n6) Listar empleados\n7) Ordenar empleados\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10) Salir\n","Error\n", 1, 3, 0, &opcion);
        switch(opcion)
        {
        case 1:
            if(flagCsv == 0 && flagBin !=1)
            {
                controller_loadFromText("data.csv",listaEmpleados);

                flagCsv = 1;
            }
            else
            {
                printf("ya se cargaron los datos previamente\n");
            }
            system("pause");
            break;
        case 2:
            if(flagCsv !=1 && flagBin == 0)
            {

                controller_loadFromBinary("data.bin", listaEmpleados);
                flagBin = 1;
            }
            else
            {
                printf("ya se cargaron los datos previamente\n");
            }
            system("pause");
            break;
        case 3:
            if(flagCsv == 1 || flagBin == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 4:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 5:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
               printf("No ha cargado los datos aun\n");
            }
            system("pause");
            break;
        case 6:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;;
        case 7:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;;
        case 8:
            if(flagCsv == 1|| flagBin == 1)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 9:
            if(flagCsv == 1|| flagBin == 1)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 10:
                printf("Los datos no seran guardados\n Seguro que desea salir? ");
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
                        ll_deleteLinkedList(listaEmpleados);
                        printf("Gracias. Vuelva pronto!!!\n");
                        return 0;
                    }
            break;
        default:
            printf("Opcion incorrecta. Reingrese\n");
            system("pause");
        }

        system("cls");
    }
    while(strcmp(salir,"si")!= 0);
    return 0;
}
