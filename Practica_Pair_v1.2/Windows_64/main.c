#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* empleados;
    empleados=al_newArrayList();
    Employee *aux;
    aux=(Employee*)malloc(sizeof(Employee));
    FILE *pFile;
    pFile=fopen("data.csv","r");
    int opcion=0;
    char seguir='s';
    int error;
    while(seguir!='n')
    {   system("cls");
        printf("Menu:\n\t1. Parse del archivo data.csv\n\t2. Listar Empleados\n\t3. Ordenar por nombre\n\t4. Agregar un elemento\n\t5. Elimina un elemento\n\t6. Listar Empleados (Desde/Hasta)\n\t7. Salir\n\t");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            error=parserEmployee(pFile,empleados);
            break;
        case 2:
            for(int i=0;i<al_len(empleados);i++)
                {
                    aux=(Employee*)al_get(empleados,i);
                    employee_print(aux);
                }
                system("pause");
            break;
        case 3:
            seguir='n';
            break;
        }
    }


    fclose(pFile);
    return 0;
}
/*Employee *e;//={1,"Juan","Gomez",1};
    Employee *e2;//={2,"Juan","Gomez",2};
     Employee *aux;
    e=(Employee*)malloc(sizeof(Employee));
    aux=(Employee*)malloc(sizeof(Employee));
    e2=(Employee*)malloc(sizeof(Employee));
    e->id=5;
    e2->id=6;
    strcpy(e->name,"Juan");
    strcpy(e2->name,"Luis");
    strcpy(e->lastName,"Gomez");
    strcpy(e2->lastName,"Sua");
    e->isEmpty=1;
    e2->isEmpty=1;
    empleados=al_newArrayList();
    al_add(empleados,e);
    al_add(empleados,e2);
    printf("Hay %d elementos\n",al_len(empleados));
    for(int i=0;i<al_len(empleados);i++)
    {
        aux=(Employee*)al_get(empleados,i);
        printf("id: %d\t-Nombre: %s\tApellido: %s\n",aux->id,aux->name,aux->lastName);
    }*/
