#include "Empleados.h"

int initEmployees(Employee empleados[], int tam)
{
    int estado = -1; // inicializamos el estado en -1

    for(int i =0;i<tam;i++) // Recorremos el array de tipo y verificamos que en el campo isEmpty no haya ningun dato cargado
    {
        empleados[i].isEmpty = 0; // Le ponemos estado en 0 para permitir que se puedan cargar datos(empleados) a ese campo
        estado = 0;
    }
 return estado;
}

int addEmployee(Employee empleados[], int tam, int id, char name[], char lastName[], float salary, int sector)
{
    int i;
    int indice;
    int estado = -1; // inicializamos el estado en -1
    indice = buscarLibre(empleados, tam);   // Adentro de esta variable indice guardamos un espacio libre y que no sea nulo llamando a la funcion buscar libre

     for(i=0;i<tam;i++)
     {
        if(indice != -1)
        {
            //Aca a la estructura o entidad de EMPLEADOS le asignamos cada campo con un espacio libre en memoria de ese indice
            empleados[indice].id = id;
            empleados[indice].salary = salary;
            empleados[indice].sector = sector;
            empleados[indice].isEmpty = 1;
            strcpy(empleados[indice].name, name); //Strcpy es para copiar el contenido de una cadena a otra, en este caso copiamos la cadena del campo nombre a la función
            strcpy(empleados[indice].lastName, lastName); //Strcat es para concatenar una cadena hacia otra
            estado = 0; // Ponemos el estado en 0 para que recorra la lista y retornamos ese estado
            break;
        }
     }
    return estado;
}

int buscarLibre(Employee empleados[], int tam)
{
    int indice = -1;    // Inicializa el indice en -1 por si es nulo
    int i;

    for(i=0;i<tam;i++)  // Recorremos la lista de empleados
    {
        if(empleados[i].isEmpty != 1)   //Preguntamos si hay espacio libre en memoria para poder agregar un empleado
        {
            indice = i; // guardamos ese espacio libre para ese empleado que se quiera agregar
            break;
        }
    }
    return indice;
}

int findEmployeeById(Employee empleado[], int tam, int id)
{
    int i;
    int idEncontrado = -1; //Inicializamos el IdEncontrado en -1 como null

    for (i=0;i<tam;i++) //Recorremos la lista de Id
    {
        if(id == empleado[i].id && empleado[i].isEmpty == 1) // Preguntamos si en la lista de empleados tienen un id asignado
        {
            idEncontrado = i; // le asignamos ese id en particular a un empleado y retornamos el id
            break;
        }
    }
    return idEncontrado;
}

int removeEmployee(Employee empleado[], int tam, int id)
{
    int estado = -1;
    int index;

    index = findEmployeeById(empleado, tam, id);
    if(index != -1)
    {
        empleado[index].isEmpty = 0;
        estado = 0;
    }
    return estado;
}
int mostrarSalaryPromedioSuperiorPromedio(Employee empleado[], int tam)
{
    float total;
    float prom;
    int superior;
    int estado = 0;

    total = salaryTotal(empleado, tam);
    prom = promedio(empleado, tam);
    superior = superiorPromedio(empleado, tam);

    printf("\nsuma total de salarios: %f\n", total);
    printf("\npromedio total de salarios: %f\n", prom);
    printf("\ntotal de empleados que superan el promedio de salarios: %d\n", superior);

    return estado;
}

int modificarEmployee(Employee empleado [], int tam,int id)
{
    int estado = -1;
    int index;
    int auxSector;
    char auxName[30];
    char auxLastName[30];
    float auxSalary;
    int opcion;

    index = findEmployeeById(empleado,tam,id);

   if (index != -1)
   {
       printf("1-modificar sector\n2-modificar nombre\n3-modificar apellido\n4-modificar salario");
       scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            getInt("Ingrese nuevo sector: ","error\n",1,3,10,&auxSector);
            empleado[index].sector = auxSector;
            break;
            case 2:
            getName("Ingrese nuevo nombre: ","error\n",4,20,10,auxName);
            strcpy(empleado[index].name,auxName);
            break;
            case 3:
            getName("Ingrese nuevo apellido: ","error\n",4,20,10,auxLastName);
            strcpy(empleado[index].lastName,auxLastName);
            break;
            case 4:
            getFloat("Ingrese nuevo salario: ","error\n",0,50000,10,&auxSalary);
            empleado[index].salary = auxSalary;
            break;
            default:
            printf("opcion incorrecta sera devuelto al menu principal");
        }

        estado = 0;
   }
    return estado;
}


int sortEmployeeByNameAndAverage(Employee empleados[], int tam)
{
    int i;
    int j;
    int estado = -1;
    Employee auxempleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if (empleados[i].isEmpty == 1)
            {
                if(strcmp(empleados[i].lastName,empleados[j].lastName)>0)
                {
                    auxempleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxempleado;
                    estado = 0;
                }

                else
                {
                    if(strcmp(empleados[i].lastName,empleados[j].lastName)==0)
                    {
                        if(empleados[i].sector>empleados[j].sector)
                        {
                            auxempleado = empleados[i];
                            empleados[i] = empleados[j];
                            empleados[j] = auxempleado;
                        }
                    }
                }
            }
        }
    }
    return estado;
}

float salaryTotal(Employee empleados [], int tam)
{
    int i;
    float total=0;

    for (i=0;i<tam;i++)
    {
        if (empleados[i].isEmpty == 1)
        {
            total += empleados[i].salary;
        }
    }
    return total;
}

float promedio(Employee empleados[], int tam)
{
    int i;
    int cont=0;
    float total;
    float prom;

    total = salaryTotal(empleados,tam);

    for (i=0;i<tam;i++)
    {
        if (empleados[i].isEmpty == 1)
        {
            cont++;
        }
    }
    prom = total / cont;
    return prom;
}

int superiorPromedio(Employee empleados [], int tam)
{
    float prom;
    int i;
    int cont=0;

    prom = promedio(empleados,tam);

    for (i=0;i<tam;i++)
    {
        if (empleados[i].salary > prom && empleados[i].isEmpty == 1)
        {
            cont++;
        }
    }
    return cont;
}

int printEmployees(Employee empleados[], int tam)
{
    int i;
    int estado= -1;

    printf("Id\tName\tLast Name\tSalary\tSector\n");
    for(i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==1)
        {
            printf("%d\t%s\t%s\t  %13.2f\t %2d\n",
            empleados[i].id,
            empleados[i].name,
            empleados[i].lastName,
            empleados[i].salary,
            empleados[i].sector);
            printf("\n");
            estado= 0;
        }
    }
    return estado;
}
