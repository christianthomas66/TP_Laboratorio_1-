#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "musicos.h"
#include "parser.h"

int parser_MusicoFromText(FILE* miFile, LinkedList* listaMusico)
{
	eMusicos* pMusico;
    int retorno = 0;

	char id[200];
	char nombre[200];
	char apellido[200];
	char instrumento[200];
	char edad[200];
	char altura[200];

	if(miFile != NULL && listaMusico != NULL)
	{
	    fscanf(miFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, instrumento, edad, altura);
		do
		{
			if(fscanf(miFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, instrumento, edad, altura) == 5)
			{
				pMusico = musicos_newParametros(id, nombre, apellido, instrumento, edad, altura);

				if(pMusico != NULL)//osea si pudo cargar
				{
					ll_add(listaMusico, pMusico);
					retorno = 1;
				}
			}
			else
			{
				break;
			}

		}while(feof(miFile) == 0);
	}
return retorno;
}

int parser_MusicoFromBinary(FILE* miFile , LinkedList* listaMusico)
{
	int retorno = 1;
	eMusicos* pMusico;

	if(miFile != NULL)
	{
		do
		{
			pMusico = musico_New();
			if(fread(pMusico, sizeof(eMusicos), 1, miFile) == 1)
			{
				ll_add(listaMusico, pMusico);
				printf("Agregado con exito\n");
				retorno = 0;
			}
		}while(!feof(miFile));
	}

    return retorno;
}


int cargarTexto(char* path, LinkedList* listaMusico)
{
	FILE* miFile;
	int retorno = 1;

	miFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(miFile != NULL)
	{
		if(parser_MusicoFromText(miFile, listaMusico) == 0)
		{
		    //Si todo salio bien cambia a 0
		    retorno = 0;
			printf("\nLos datos de los jugadores en modo texto fueron cargados corretamente\n\n");
		}
	}

	else
	{
		printf("Error\n");
	}

	fclose(miFile);

    return retorno;

}

int cargarBinario(char* path , LinkedList* listaMusico)
{
	FILE* miFile;
	int retorno = 1;

	miFile = fopen(path, "rb"); //Abre el archivo que no sea de texto para leerlo, si es que existe.

	if(miFile != NULL)
	{
		if(!(parser_MusicoFromBinary(miFile, listaMusico)))
		{
		    //Si todo salio bien, retorno pasa a valer 0
			retorno = 0;
			printf("Los datos de los musico en modo binario fueron cargados corretamente\n\n");
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}

    }
    else
    {
        printf("Error\n");
    }
	fclose(miFile);
    return retorno;
}


int guardarComoTexto(char* path, LinkedList* listaMusico)
{
	FILE* miFile;
	eMusicos* pMusico;
	int retorno = 0;

	int auxId;
	char auxNombre[128];
	char auxApellido[128];
	char auxInstrumento[128];
	int auxEdad;
	float auxAltura;


	if(listaMusico != NULL && path != NULL)
	{
		miFile = fopen(path, "w");
		if(miFile != NULL)
		{
			retorno = 1;
			for(int i = 0; i < ll_len(listaMusico); i++)
			{
				pMusico = (eMusicos*)ll_get(listaMusico, i);

                musico_GetId(pMusico, &auxId);
                musico_GetNombre(pMusico, auxNombre);
                musico_GetApellido(pMusico, &auxApellido);
                musico_GetInstrumento(pMusico, &auxInstrumento);
                musico_GetEdad(pMusico, &auxEdad);
                musico_GetAltura(pMusico, &auxAltura);

                fprintf(miFile, "%d,%s,%s,%s,%d,%.2f\n", auxId, auxNombre, auxApellido, auxInstrumento, auxEdad, auxAltura);
			}

			fclose(miFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(retorno == 0)
        {
            printf("Error\n");
        }
	}
    return retorno;
}


nt guardarComoBinario(char* path, LinkedList* listaMusico)
{
	int retorno = 1;
	FILE* miFile;
	eMusicos* pMusico;

	if(listaMusico != NULL && path != NULL)
	{
		miFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(listaMusico); i++)
		{
			pMusico = (eMusicos*) ll_get(listaMusico, i);
			if(pMusico != NULL)
            {
                fwrite(pMusico, sizeof(eMusicos), 1, miFile);
                retorno = 0;
            }
		}

		if(retorno == 0)
        {
            printf("Archivo guardado correctamente\n");
        }

		fclose(miFile);
	}

    return retorno;
}



