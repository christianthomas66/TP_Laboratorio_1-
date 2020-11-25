#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "musicos.h"

eMusicos* musico_New()
{
    eMusicos* pMusico;
    pMusico = (eMusicos*) malloc(sizeof(eMusicos));

return pMusico;
}

void musicos_borrar(eMusicos* this)
{
    if(this != NULL)
        {
            free(this);
        }
}

eMusicos* musicos_newParametros(char* id, char* nombre, char* apellido, char* instrumento, char* edad, char* altura)
{
   eMusicos* pMusico = NULL;
	pMusico = musico_New();

	if(id != NULL && nombre != NULL && apellido != NULL && instrumento != NULL && edad != NULL && altura != NULL)
	{

		if(musico_SetId(pMusico, atoi(id)) == -1 ||
            musico_SetNombre(pMusico, nombre) == -1 ||
            musico_SetApellido(pMusico, atoi(apellido)) == -1 ||
            musico_SetInstrumento(pMusico, atoi(instrumento)) == -1 ||
            musico_SetEdad(pMusico, atoi(edad)) == -1 ||
            musico_SetAltura(pMusico, atof(altura)))
            {
                musicos_borrar(pMusico);
                pMusico = NULL;
            }
            else
            {
                musico_SetId(pMusico, atoi(id));
                musico_SetNombre(pMusico, nombre);
                musico_SetApellido(pMusico, atoi(apellido));
                musico_SetInstrumento(pMusico, atoi(instrumento));
                musico_SetEdad(pMusico, atoi(edad));
                musico_SetAltura(pMusico, atof(altura));
            }
	}
return pMusico;
}

int pais_SetId(eMusicos* this, int id)
{
    int retorno = 0;
    if(this != NULL)
        {
            this->id = id;
            retorno = 1;
        }
return retorno;
}

int pais_GetId(eMusicos* this, int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
        {
            *id = this->id;
            retorno = 1;
        }
return retorno;
}

int pais_SetNombre(eMusicos* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
return retorno;
}

int pais_GetNombre(eMusicos* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
return retorno;
}

int musico_SetApellido(eMusicos* this, char* apellido)
{
    int retorno = 0;
    if(this != NULL && apellido != NULL)
        {
            this->apellido = apellido;
            retorno = 1;
        }
return retorno;
}

int musico_GetApellido(eMusicos* this, char* apellido)
{
    int retorno = 0;
    if(this != NULL && apellido != NULL)
        {
            *apellido = this->apellido;
            retorno = 1;
        }
return retorno;
}

int musico_SetInstrumento(eMusicos* this, char* instrumento)
{
    int retorno = 0;
    if(this != NULL && instrumento != NULL)
        {
            this->instrumento = instrumento;
            retorno = 1;
        }
return retorno;
}

int musico_GetInstrumento(eMusicos* this, char* instrumento)
{
    int retorno = 0;
    if(this != NULL && instrumento != NULL)
        {
            *instrumento = this->instrumento;
            retorno = 1;
        }
return retorno;
}

int musico_SetEdad(eMusicos* this, int edad)
{
    int retorno = 0;
    if(this != NULL && edad != NULL)
        {
            this->edad = edad;
            retorno = 1;
        }
return retorno;
}

int musico_GetEdad(eMusicos* this, int* edad)
{
    int retorno = 0;
    if(this != NULL && edad != NULL)
        {
            *edad = this->edad;
            retorno = 1;
        }
return retorno;
}

int musico_SetAltura(eMusicos* this, float altura)
{
    int retorno = 0;
    if(this != NULL)
        {
            this->altura = altura;
            retorno = 1;
        }
return retorno;
}

int musico_GetAltura(eMusicos* this, float* altura)
{
    int retorno = 0;
    if(this != NULL)
        {
            *altura = this->altura;
            retorno = 1;
        }
return retorno;


}



int filterExisotos(void* pFilter)
{
    int retorno = 0;
    if(pFilter != NULL)
        {
            eMusicos* pMusico = (eMusicos*)pFilter;
            if((pMusico->edad) <= 5000)
                {
                    retorno = 1;
                }
        }
return retorno;
}

int filterHorno(void* pFilter)
{
    int retorno = 0;

    if(pFilter != NULL)
        {
            eMusicos* unPais = (eMusicos*)pFilter;
            if(unPais->apellido >(unPais->instrumento)*3)
                {
                    retorno = 1;
                }
        }
return retorno;
}

int obetenerId(int* id)
{
    int retorno = 0;
    *id = 20;

    FILE* miFilie;
    miFilie = fopen("proximoId.bin", "rb");
    if(miFilie != NULL)
    {
        fread(id, sizeof(int), 1, miFilie);
        fclose(miFilie);
        retorno = 1;
    }
    return retorno;
}

int actualizarId(int id)
{
    int retorno = 0;
    id++;

    FILE* miFile = fopen("proximoId.bin", "wb");
    if(miFile != NULL)
    {
        fwrite(&id, sizeof(int), 1, miFile);

        fclose(miFile);
        retorno = 1;
    }
    return retorno;
}


int altaMusico(char* path , LinkedList* listaMusico)
{
    int proxId;
	char auxNombre[128];
	char auxApellido[128];
	char auxInstrumento[21];
	int auxEdad;
	float auxAltura;
	//int flag = 0;
	int exito = 1;

	eMusicos* pMusico = musico_New();

	if(listaMusico != NULL && pMusico != NULL)
	{
		getString(auxNombre, 128, 2, "Ingrese nombre: ", "Error, nombre invalido. Reintente");
        getString(auxApellido, 128, 2, "Ingrese apellido: ", "Error, nombre invalido. Reintente");

		printf("Ingrese nombre de usuario: ");
		scanf("%s", auxApellido);
		getSt(auxInstrumento, 21, 2, "Ingrese pais: ", "Error, pais invalido. Reintente");
        utn_getEntero(&auxEdad, 2, "Ingrese cantidad de puntos (max. 5 cifras): ", "Error, cantidad invalida.  Reintente\n", 0, 99999);


        proxId = jugador_proxId(listaMusico) + 1;

			if(proxId >= 0)
			{
				if(!jugador_setId(pMusico, proxId) &&
				   !jugador_setNombreCompleto(pMusico, auxNombre) &&
				   !jugador_setNombreUsuario(pMusico, auxApellido) &&
				   !jugador_setPais(pMusico, auxInstrumento) &&
				   !jugador_setPuntos(pMusico, auxEdad))
				{
					ll_add(listaMusico, pMusico);
					printf("Se realizo el alta de un nuevo jugador\n");
				}
				else
				{
					free(pMusico);
				}
			}

		else
		{
			free(pMusico);
		}
	}

    return exito;
}



int listarMusicos(LinkedList* listaMusico)
{
    eMusicos* pMusico;
    int retorno = 0;

    int auxId;
    char auxNombre[100];
    int auxApellido[100];
    int auxInstrumentos[100];
    int auxEdad;
    float auxAltura;

    int tamLista;

    tamLista = ll_len(listaMusico);

    if(listaMusico != NULL)
    {
        if(tamLista > 0)
        {
            printf("Id\tNombre\t  Apellido\t\t\t  Instrumento\t  Edad\t     Altura\n");

            for(int i = 0; i < tamLista; i++)
            {
                pMusico = (eMusicos*)ll_get(listaMusico, i);

                musico_GetId(pMusico, &auxId);
                musico_GetNombre(pMusico, auxNombre);
                musico_GetApellido(pMusico, &auxApellido);
                musico_GetInstrumento(pMusico,&auxInstrumentos);
                musico_GetEdad(pMusico, &auxEdad);
                musico_GetAltura(pMusico, &auxAltura);

                printf("%d  %13s %10s  %10s  %d  %.2f\n",auxId, auxNombre, auxApellido, auxInstrumentos, auxEdad, auxAltura);
            }
            retorno = 1;

        }
    }
return retorno;
}

int ordenarMusicosPorNombre(void* nombre1 , void* nombre2)
{
    int retorno;
    int nom1;
    int nom2;

    musico_GetNombre(nombre1, &nom1);
    musico_GetNombre(nombre2, &nom2);

    if(nom1 > nom2)
    {
        retorno = 1;
    }
    else if(nom1 < nom2)
    {
        retorno = -1;
    }

    return retorno;
}

int ordenarMusicosPorApellido(void* apellido1 , void* apellido2)
{
    int retorno;
    int apellidoUno;
    int apellidoDos;

    musico_GetNombre(apellido1, &apellidoUno);
    musico_GetNombre(apellido2, &apellidoDos);

    if(apellidoUno > apellidoDos)
    {
        retorno = 1;
    }
    else if(apellidoUno < apellidoDos)
    {
        retorno = -1;
    }
    return retorno;
}


LinkedList* paisesMasCatigados(LinkedList* this)
{
    LinkedList* listaMap = NULL;
    int cantMuertos;
    int cantMayor;
    int flag = 0;
    eMusicos* pElement = NULL;

    if(this != NULL)
    {
        listaMap = ll_newLinkedList();

        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pais_GetMuertos(pElement, &cantMuertos);

            if(!flag || cantMuertos > cantMayor)
            {
                cantMayor = cantMuertos;
                flag = 1;
            }
        }

        pElement = NULL;
        for(int i = 0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pais_GetMuertos(pElement, &cantMuertos);

            if(cantMuertos == cantMayor){
                ll_add(listaMap, pElement);
            }
        }
    }
    else
    {
        printf("Error\n");
    }

    return listaMap;
}


int datosRandom(void* a)
{
    int retorno = 0;

    if(a != NULL)
        {
            ePais* unPais = (ePais*)a;
            unPais->recuperados = 50000 + rand() % (1000000-50000);
            unPais->infectados =  40000 + rand() % (2000000-40000);
            unPais->muertos = 1000 + rand() % (50001-1000);
            retorno = 1;
        }
return retorno;
}
