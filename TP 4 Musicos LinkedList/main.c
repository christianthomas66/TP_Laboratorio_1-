#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "musicos.h"
#include "parser.h"

int main()
{
    int opcion = 0;
    char salir[3];
    char aux;
    //int flag = 0;

    LinkedList* listaPrincipal = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;

    //LinkedList* listaFiltradaExitosos = NULL;
    //LinkedList* listaFiltradaHorno = NULL;
    //LinkedList* listaPaisesMasCastigados = NULL;

    do
    {   strcpy(salir,"no");
        getInt("------ MENU DE MUSICOS ------\
               n1) Cargar archivo de datos .csv (modo texto)\
               n2) Cargar archivo de datos .csv (modo binario)\
               n3) Alta musico\
               n4) Modificar datos del musico\
               n5) Baja musico\
               n6) Ordenar musicos\
               n7) Guardar los datos de los musicos en el archivo .csv (modo texto)\
               n8) Guardar los datos de los musicos en el archivo .csv (modo binario)\
               n9) Salir\
               nElija una opcion deseada:","Error\n", 1, 3, 0, &opcion);
        switch(opcion)
        {
        case 1:

                if(cargarTexto("pandemia.csv", listaPrincipal) == 1)
                    {
                        printf("Archivo de texto cargado con exito!!!\n");
                    }
                else
                    {
                        printf("No se pudo cargar el archivo. Problemas!!!\n");
                    }
            system("pause");
            break;
        case 2:
                if(cargarBinario("musicos.bin"), list)

            /*else
            {
                printf("ya se cargaron los datos previamente\n");
            }*/
            system("pause");
            break;
        case 3:
                listaMapeada = ll_map(listaPrincipal, datosRandom);
                listarPaises(listaMapeada);
                system("pause");
            break;
        case 4:
                listaFiltradaExitosos = ll_filter(listaPrincipal, filterExisotos);
                guardarComoTexto("paisesExitosos.csv", listaFiltradaExitosos);


            /*
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            */
            system("pause");
            break;
        case 5:

                listaFiltradaHorno = ll_filter(listaPrincipal, filterHorno);
                guardarComoTexto("paisesEnElHorno.csv", listaFiltradaHorno);
            /*
            else
            {
               printf("No ha cargado los datos aun\n");
            }*/
            system("pause");
            break;
        case 6:

                ll_sort(listaPrincipal, ordenarPaisxInfectados, 1);
                listarPaises(listaPrincipal);
            system("pause");
            break;;
        case 7:
            listaPaisesMasCastigados = paisesMasCatigados(listaPrincipal);
            listarPaises(listaPaisesMasCastigados);


            /*
            else
            {
                printf("No ha cargado los datos aun \n");
            }*/
            system("pause");
            break;;
        case 8:
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
                        printf("Gracias. Vuelva pronto!!!\n");
                        return 0;
                    }


            system("pause");
            break;
        case 10:

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
