#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char instrumento[128];
    int edad;
    float altura;
}eMusicos;

#endif // PAIS_H_INCLUDED

eMusicos* musico_New();
eMusicos* musicos_newParametros(char* id, char* nombre, char* apellido, char* instrumento, char* edad, char* altura);

void paises_borrar(eMusicos* this);
//FUNCIONES SETTER
int musico_SetId(eMusicos* this, int id);
int musico_SetNombre(eMusicos* this, char* nombre);
int musico_SetApellido(eMusicos* this, char* apellido);
int musico_SetInstrumento(eMusicos* this, char* instrumento);
int musico_SetEdad(eMusicos* this, int edad);
int musico_SetAltura(eMusicos* this, float altura);

//FUNCIONES GETTER
int musico_GetId(eMusicos* this, int* id);
int musico_GetNombre(eMusicos* this, char* nombre);
int musico_GetApellido(eMusicos* this, char* apellido);
int musico_GetInstrumento(eMusicos* this, char* instrumento);
int musico_GetEdad(eMusicos* this, int* edad);
int musico_GetAltura(eMusicos* this, float* altura);


//int comparar_infectados(void* infectado1, void* infectado2);
int listarMusicos(LinkedList* listamusico);

int ordenarMusicosPorNombre(void* nombre1 , void* nombre2);



