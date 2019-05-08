#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funtionsABM.h"
#include "validation.h"


/** \brief Confirms that the new employee is added and saves the data stored in the auxiliaries in the array
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \param Id stored in auxiliary for user
 * \param Value of index stored for user in auxiliary
 * \param String auxiliary where is stored the name adding for user
 * \param String auxiliary where is stored the last name adding for user
 * \param Value floating auxiliary where stored the salary of employee
 * \param Value auxiliary where stored the sector
 * \return returns 0 if the function was carried out correctly, -1 if the operation is not charged or canceled
 */
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

/** \brief Search if the id is occupied by another employee in the array
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \return Returns index of the position of the array free
 */
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

/** \brief Indicates all the positions of the array of employees that is free, the function puts the flag "isEmpy" in 1 (TRUE) in all positions of the array
 *
 * \param Employee structure array
 * \param Size of the structure array "employee"
 * \return Returns -1 for an error or 0 if the function was carried out correctly
 */
int initEmployee(Employee employee[], int len)
{
    for(int i=0;i<len;i++)
    {
        employee[i].isEmpy=0;
    }
    return 0;
}

//-------------------------------------------------------------------------------------------

/** \brief Initializes the sector array "sectors". Give value 1 the first position of the array and increase in the next position to the maximum value
 *
 * \param Array of sectors integers
 * \param Size of the array "sectors"
 * \return Returns 0 if the function was carried out correctly
 */
int initSector(int sectors[],int len)
{
    for(int i=0;i<len;i++)
    {
        sectors[i]=i+1;
    }
    return 0;
}

//-------------------------------------------------------------------------------------------

/** \brief Function printing ABM options menu
 *
 * \return Returns -1 if the function fails or returns the integer value of the chosen option (from 0 to 4)
 */
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

/** \brief Submenu, ordering
 *
 * \return Returns -1 if the function failed or returns the integer of the option chosee
 */

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

/** \brief Modify the name, last name, salary or sector of the employee array
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \param Stored the ID of the employee
 * \return returns 1 if the function was carried out correctly, or returns -1 if failed
 */
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

/** \brief Show of data of an employee
 *
 * \param Receives a position of the employee array
 * \return Returns 0 if the function was carried out correctly
 */
int printEmployee (Employee employee)
{
    printf("%d  %10s  %10s    %.2f    %d",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
    return 0;
}

//-------------------------------------------------------------------------------------------

/** \brief Show list of the sectors
 *
 * \param Array of integers of sectors
 * \param Integer value of the employee array length
 * \return Returns the auxiliary whit the value save of the sector
 */
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

/** \brief Delete employee by id putting the variable "isEmpy" in value 1.
 *
 * \param Array of strut of employee.
 * \param Integer value of the employee array length.
 * \param Id of the employee to delete.
 * \return Returns 0 if the function was carried out correctly, or -1 if the function failed.
 */
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

/** \brief Search in the array of the employee structure for the first free position, looking for the variable "isEmpy" in 0
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \return Returns index of the position of the array free
 */
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

/** \brief Sort the list of employee depending on the option
 *
 * \param Array of strut of employee.
 * \param Integer value of the employee array length.
 * \param Option of sort
 * \param Array of sectors integers
 * \param Length of array "sectors"
 * \return Returns 0 if the function was carried out correctly
 *
 */

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
