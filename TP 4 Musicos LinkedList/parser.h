#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
int parser_MusicoFromText(FILE* miFile, LinkedList* listaMusico);
int parser_MusicoFromBinary(FILE* miFile , LinkedList* listaMusico);

int cargarTexto(char* path , LinkedList* listaMusico);
int cargarBinario(char* path , LinkedList* listaMusico);

int guardarComoTexto(char* path, LinkedList* listaMusico);
int guardarComoBinario(char* path, LinkedList* listaMusico)


//int parser_PaisFromBinary(FILE* miFile, LinkedList* pMiLista);
