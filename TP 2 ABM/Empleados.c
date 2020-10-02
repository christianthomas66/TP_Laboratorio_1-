#include "Empleados.h"

int initEmployees(Employee empleados [], int t)
{
    int i;
    int estado = -1;

    for (i=0;i<t;i++)
    {
    empleados[i].isEmpty=0;
    estado = 0;
    }

 return estado;
}


int addEmployee(Employee empleados [], int t, int id, char name[],char lastName[],float salary,int sector)
{

    int i;
    int indice;
    int estado= -1;
    indice = buscarLibre(empleados, t);


 for (i=0;i<t;i++)
 {
    if(indice!= -1)
    {

        empleados [indice].id = id;
        empleados [indice].salary = salary;
        empleados [indice].sector = sector;
        empleados [indice].isEmpty =1;
        strcpy(empleados[indice].name,name);
        strcpy(empleados[indice].lastName,lastName);



        estado=0;
        break;
    }


 }


return estado;

}

int buscarLibre( Employee empleados [], int t)
{
    int indice = -1;
    int i;

    for(i=0;i<t;i++)
    {
        if(empleados[i].isEmpty!= 1)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

int findEmployeeById(Employee empleado[], int t,int id)


{
    int i;
    int idEncontrado = -1;

    for (i=0;i<t;i++)

    {

        if (id == empleado[i].id && empleado[i].isEmpty == 1)

        {
            idEncontrado = i;
            break;
        }
    }

    return idEncontrado;



}


int removeEmployee(Employee empleado [], int t,int id)

{
    int estado = -1;
    int index;

    index = findEmployeeById(empleado,t,id);

   if (index != -1)
   {

       empleado[index].isEmpty = 0;
       estado = 0;
   }


    return estado;
}
int mostrarSalaryPromedioSuperiorPromedio (Employee empleado [],int t)
{

    float total;
    float pro;
    int super;
    int estado=0;

    total = salaryTotal(empleado,t);
    pro = promedio(empleado,t);
    super = superiorPromedio(empleado,t);






        printf("\nsuma total de salarios: %f\n",total);
        printf("\npromedio total de salarios: %f\n",pro);
        printf("\ntotal de empleados que superan el promedio de salarios: %d\n",super);

        return estado;
}

int modificarEmployee(Employee empleado [], int t,int id)

{
    int estado = -1;
    int index;
    int auxSector;
    char auxName[30];
    char auxLastName[30];
    float auxSalary;
    int opcion;

    index = findEmployeeById(empleado,t,id);

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


int sortEmployeeByNameAndAverage(Employee empleados[], int t)
{
    int i;
    int j;
    int estado = -1;
    Employee auxempleado;

    for(i=0; i<t-1; i++)
    {
        for(j=i+1; j<t; j++)
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

float salaryTotal (Employee empleados [], int t)

{

    int i;
    float total=0;

    for (i=0;i<t;i++)
    {

        if (empleados[i].isEmpty == 1)
        {
            total += empleados[i].salary;


        }
    }
    return total;
}

float promedio (Employee empleados [], int t)

{
    int i;
    int cont=0;
    float total;
    float prom;

    total = salaryTotal(empleados,t);

     for (i=0;i<t;i++)
    {

        if (empleados[i].isEmpty == 1)
        {
            cont++;
        }
    }

    prom = total / cont;

    return prom;
}


int superiorPromedio (Employee empleados [], int t)
{
    float prom;
    int i;
    int cont=0;

    prom = promedio(empleados,t);

    for (i=0;i<t;i++)
    {
        if (empleados[i].salary > prom && empleados[i].isEmpty == 1)
        {
            cont++;
        }
    }

    return cont;
}

int printEmployees (Employee empleados [],int t)

{
    int i;
    int estado= -1;

            printf("Id\tName\tLast Name\tSalary\tSector\n");
    for (i=0;i<t;i++)
    {
        if (empleados[i].isEmpty==1)
        {
            printf("%d\t%s\t%s\t%13.2f\t%2d\n",empleados[i].id,empleados[i].name,empleados[i].lastName,empleados[i].salary,empleados[i].sector);

            estado= 0;
        }
    }

    return estado;
}
