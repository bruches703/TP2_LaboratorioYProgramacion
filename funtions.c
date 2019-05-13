#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funtionsABM.h"
#include "validation.h"


int addEmployee(Employee employee[], int len, int id, int index, char name[],char lastName[],float salary,int sector)
{
    char confirm;

    printf("\n\nConfirma el ingreso del empleado? s/n: ");
    fflush(stdin);
    confirm=getche();
    confirm=validationChar(confirm);

    if(confirm=='s')
    {
        employee[index].isEmpy=1;
        employee[index].id=id;
        strcpy(employee[index].name,name);
        strcpy(employee[index].lastName,lastName);
        employee[index].salary=salary;
        employee[index].sector=sector;
        return 0;
    }
    else
    {
        printf("Canselado\n");
        return -1;
    }
}

//-------------------------------------------------------------------------------------------

int findEmployeeById(Employee employee[], int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(employee[i].isEmpy == 1 && employee[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

//-------------------------------------------------------------------------------------------


int initEmployee(Employee employee[], int len)
{
    for(int i=0;i<len;i++)
    {
        employee[i].isEmpy=0;
    }
    return 0;
}

//-------------------------------------------------------------------------------------------


int initSector(int sectors[],int len)
{
    for(int i=0;i<len;i++)
    {
        sectors[i]=i+1;
    }
    return 0;
}

//-------------------------------------------------------------------------------------------


int menu (void)
{
    int option;
    system("cls");
    printf("**********Menu de opciones**********\n\n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Informar\n");
    printf("0-Salir");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    return option;
}

//-------------------------------------------------------------------------------------------



int menuOfSort (void)
{
    int option;
    system("cls");
    printf("**********Menu de opciones**********\n\n");
    printf("1-Mostrar empleados por apellidos A-Z\n");
    printf("2-Mostrar empleados por apellidos Z-A\n");
    printf("3-Mostrar por sector\n");
    printf("0-Volver al menu anterior");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    option=validationMenu(option,0,3);
    return option;
}

//-------------------------------------------------------------------------------------------


int modifyEmployee (Employee employee[], int len, int file)
{
    char confirm='n';
    char entry='n';
    char name[100];
    char lastName[100];

    int option;
    int sector;

    float salary;

    printEmployee(employee[file]);
    printf("\nConfirma la modificacion del empleado? s/n: ");
    fflush(stdin);
    entry=getche();
    entry=validationChar(entry);

    if(entry=='s')
    entry=tolower(entry);
    {
            do
            {
                    printf("\n1-Modificar nombre");
                    printf("\n2-Modificar apellido");
                    printf("\n3-Modificar salario");
                    printf("\n4-Modificar sector");
                    printf("\n0-Finalizar");
                    printf("\n\nIngrese opcion: ");
                    fflush(stdin);
                    scanf("%d",&option);
                        switch(option)
                        {
                            case 1:
                                printf("\nIngrese nuevo nombre: ");
                                fflush(stdin);
                                scanf("%s",name);
                                strlwr(name);
                                name[0]=toupper(name[0]);
                                validationString(name,51);
                                strcpy(employee[file].name,name);

                                break;
                            case 2:
                                printf("\nInrese nuevo apellido del empleado: ");
                                fflush(stdin);
                                scanf("%s",lastName);
                                strlwr(lastName);
                                lastName[0]=toupper(lastName[0]);
                                validationString(lastName,51);
                                strcpy(employee[file].lastName,lastName);
                                break;
                            case 3:
                                printf("\nModifique el salario: ");
                                scanf("%f",&salary);
                                salary=validationPositive(salary);
                                employee[file].salary=salary;
                                break;
                            case 4:
                                printf("\nModifique el sector del trabajo: ");
                                scanf("%d",&sector);
                                validationSector(sector,1,LENGTHYSECTOR);
                                employee[file].sector=sector;
                                break;
                            case 0:
                                printf("\nVolver al menu anterior?");
                                fflush(stdin);
                                confirm=getche();
                                confirm=tolower(confirm);
                                confirm=validationChar(confirm);
                                validationChar(confirm);
                                break;
                        }
            }while(confirm=='n');
            return 1;
    }
        return -1;
}

//-------------------------------------------------------------------------------------------

int printEmployee (Employee employee)
{
    printf("%d  %10s  %10s    %.2f    %d",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
    return 0;
}

//-------------------------------------------------------------------------------------------


int printSector(int sector[], int len)
{
    int aux;

    printf("\nSeleccione sector\n");
    for(int i=0;i<len;i++)
    {
            printf("Sector %d\n",sector[i]);
    }
    printf("\nSeleccione: ");
    scanf("%d",&aux);
    return aux;
}

//-------------------------------------------------------------------------------------------


int removeEmployee(Employee employee[], int len, int id)
{
    int index;
    char confirm;

    index=findEmployeeById(employee,len,id);
    if(index==-1)
    {
        printf("El legajo no existe\n");
        system("pause");
    }
    else
    {
    printEmployee(employee[index]);
    printf("\nConfirma la baja del empleado? s/n");
    fflush(stdin);
    confirm=getche();
    confirm=tolower(confirm);
    validationChar(confirm);

        if (confirm=='s')
            {
                employee[index].isEmpy=0;
                return 0;
            }
    }
    return -1;
}

//-------------------------------------------------------------------------------------------


int searchFree(Employee employee[], int len)
{

    int index=-1;

    for(int i=0;i<len;i++)
    {
        if(employee[i].isEmpy==0)
        {
            index=i;
            break;
        }
    }
    return index;
}

//-------------------------------------------------------------------------------------------


int sortEmployees(Employee employee[],int len, int order, int sector[], int lenSector)
{
    int flag=0;
    Employee aux;
    switch(order)
    {
        case 1:
            for(int i=0;i<len-1;i++)
            {
                    for(int j=i+1;j<len;j++)
                    {
                        if (strcmp(employee[i].lastName,employee[j].lastName)>0)
                            {
                                aux=employee[i];
                                employee[i]=employee[j];
                                employee[j]=aux;
                                flag=1;
                                break;
                            }
                    }

            }
            system("cls");
            if(flag==1)
            {
            printf("Ordenado por apellidos A-Z\n\n");
            printf("Legajo    Nombre   Apellido     Salario   Sector \n");
            printf("------    ------   --------    ---------  ------ \n");
            for(int i=0;i<len;i++)
            {
                if(employee[i].isEmpy==1)
                {
                printEmployee(employee[i]);
                printf("\n");
                }
            }
            }
            else
                printf("\nNo existen empleados cargados\n");
            break;


        case 2:

            for(int i=0;i<len-1;i++)
            {
                    for(int j=i+1;j<len;j++)
                    {
                        if (strcmp(employee[i].lastName,employee[j].lastName)<0)
                            {
                                aux=employee[i];
                                employee[i]=employee[j];
                                employee[j]=aux;
                                flag=1;
                                break;
                            }
                    }

            }
            system("cls");
            if(flag==1)
            {
            printf("Ordenado por apellidos Z-A\n\n");
            printf("Legajo    Nombre   Apellido     Salario   Sector \n");
            printf("------    ------   --------    ---------  ------ \n");
            for(int i=0;i<len;i++)
            {
                if(employee[i].isEmpy==1)
                {
                printEmployee(employee[i]);
                printf("\n");
                }
            }
            }
            else
                printf("\nNo existen empleados cargados\n");
            break;


        case 3:
            for(int i=0;i<len-1;i++)
            {
                for(int j=i+1;j<len;j++)
                {
                    if (strcmp(employee[i].lastName,employee[j].lastName)>0)
                        {
                                aux=employee[i];
                                employee[i]=employee[j];
                                employee[j]=aux;
                                flag=1;
                                break;
                        }
                }
            }

            system("cls");
            for(int i=0;i<lenSector;i++)
            {
                printf("Sector %d:\n",sector[i]);
                    for(int j=0;j<len;j++)
                    {
                        if(employee[j].sector==sector[i] && employee[j].isEmpy==1)
                        {
                            printEmployee(employee[j]);
                            printf("\n");
                        }
                    }
            }
            break;
        default:
            printf("\nOpcion erronea, reingrese al menu\n");
            break;
    }
          system("pause");
        return 0;
}
