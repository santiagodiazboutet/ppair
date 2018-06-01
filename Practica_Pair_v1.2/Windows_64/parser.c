#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char name[500], lastName[500], id[500],isEmpty[500];
    Employee*empleados;

    int end;
    int error;
    char *aux;
    fseek(pFile,0,SEEK_END);
    end=ftell(pFile);
    rewind(pFile);
    while(ftell(pFile)<end)
    {
        empleados=employee_new();
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);
        sscanf(id,"%d",&empleados->id);
        strcpy(empleados->name,name);
        strcpy(empleados->lastName,lastName);
        sscanf(isEmpty,"%d",&empleados->isEmpty);
        error=al_add(pArrayListEmployee,empleados);
    }


    return error;
}
