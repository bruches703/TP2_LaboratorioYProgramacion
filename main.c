#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validation.h"
#include "funtionsABM.h"

#define LENGTHY 100
#define LONGNAME 51
#define LENGTHYSECTOR 3




int main()
{
    char name[100];                 //Auxiliar de name
    char lastName[100];             //Auxiliar de last name

    int end;                        //Toma el valor de retorno de las funciones
    int exit=0;                     //Variable de salida de doWhile
    int id;                         //Auxiliar de ID
    int idOk;                       //Comprobacion de ID correcta
    int index;                      //Variable auxiliar donde guarda indice, de ser necesario
    int orderSector[LENGTHYSECTOR]; //Vector de entero con la cantidad de setores
    int order;                      //Variable que almacena la opcion de ordenamiento (switch, case 4)
    int sector;                     //Auxiliar de sector

    float salary;                   //Auxiliar de salary


    Employee employee[LENGTHY];
        //Hardcodeo de array employee
    /*=
    {
        {1001, "david"      , "Bruches"     ,15000 ,1, 1},
        {1002, "laura"      , "Kerekes"     ,20000 ,2, 1},
        {1003, "Carla"      , "Perez"       ,19500 ,2, 1},
        {1004, "Adan"       , "Lopez"       ,18000 ,1, 1},
        {1005, "Carlos"     , "Gonzales"    ,17000 ,1, 1},
        {1006, "Pedro"      , "Meza"        ,21000 ,1, 1},
        {1007, "Ana"        , "Ruiz"        ,16500 ,1, 1},
        {1008, "Juan"       , "Biconti"     ,14800 ,2, 1},
        {1009, "Lidia"      , "Campos"      ,16000 ,3, 1},
        {1010, "Leo"        , "Sedo"        ,40000 ,1, 1},
        {1011, "Guillermo"  , "Szostak"     ,40000 ,2, 1},
        {1012, "Constanza"  , "Panasiuk"    ,40000 ,2, 1},
        {1013, "Eugenio"    , "Karpiec"     ,40000 ,2, 1},
        {1014, "Fabian"     , "Suarez"      ,40000 ,1, 1},
        {1015, "Manuel"     , "Checura"     ,40000 ,3, 1},
        {1016, "Melisa"     , "Teotis"      ,40000 ,5, 1},
        {1017, "Viviana"    , "Ocampo"      ,40000 ,4, 1},
        {1018, "Miguel"     , "Figueroa"    ,40000 ,5, 1},
        {1019, "Felipe"     , "Castillo"    ,40000 ,3, 1},

    };*/
    initSector(orderSector,LENGTHYSECTOR);  //Inicializacion de secotres (se le dara valor de 1 hasta el tope maximo dado en LENGTHYSECTOR

    initEmployee(employee,LENGTHY);         //Inicializacion de array employee (coloca las variables "isEmpy" en 1)

    //Comienzo doWhile
    do
    {
        switch(menu())
        {
        case 1:
            //Alta de empleado, almacena datos en variables auxiliares para, luego de confirmar, reemplazar los valores del array
            system("cls");
            printf("        Alta de empleado\n");


            index=searchFree(employee,LENGTHY);
            if(index == -1)
            {
                printf("\nNo hay espacios disponibles\n");
                system("pause");
                break;
            }
            else
            {
                printf("Ingrese id del empleado (1000-1100): ");
                fflush(stdin);
                scanf("%d",&id);
                id=validationId(id);
                idOk=findEmployeeById(employee,LENGTHY,id);

                if (idOk==-1)
                {
                    //Almacena el nombre en cadenas auxiliares
                    printf("Ingrese nombre del empleado: ");
                    fflush(stdin);
                    scanf("%s",name);
                    validationString(name,LONGNAME);//validacion
                    strlwr(name);
                    name[0]=toupper(name[0]);
                    strcpy(employee[index].name,name);

                    //Almacena el apellido en cadenas auxiliares
                    printf("Ingrese apellido del empleado: ");
                    fflush(stdin);
                    scanf("%s",lastName);
                    validationString(lastName,LONGNAME);//validacion
                    strlwr(lastName);
                    lastName[0]=toupper(lastName[0]);
                    strcpy(employee[index].lastName,lastName);

                    //Almacena el salario en variable auxiliar
                    printf("Ingrese el salario: ");
                    scanf("%f",&salary);
                    salary=validationPositive(salary);//validacion
                    employee[index].salary=salary;

                    //Se muestra lista de sectores para podes escoger uno y se guarda en variable auxiliar
                    sector=printSector(orderSector,LENGTHYSECTOR);
                    sector=validationSector(sector,1,LENGTHYSECTOR);//validacion
                    employee[index].sector=sector;

                    end=addEmployee(employee,LENGTHY,id,index,name,lastName,salary,sector);
                }
                else
                    printf("El legajo %d ya existe\n",id);

                if(end==0)
                    printf("\nEl empleado fue cargado correctamente\n");
                else
                    printf("\nEl empleado no fue cargado\n");

                system("pause");
                break;
            }
        case 2:
            //Modificar nombre, apellido, salary o sector de trabajo
            system("cls");
            printf("---Modificar empleado---\n\n");
            printf("Ingrese id: ");
            scanf("%d",&id);
            id=validationId(id);
            idOk=findEmployeeById(employee,LENGTHY,id);

            if(idOk==-1)
            {
                printf("No existe\n");
                system("pause");
                break;
            }
            else
            {
                end=modifyEmployee(employee,LENGTHY,idOk);
                if(end==-1)
                    {
                    printf("\nModificacion cancelada\n");
                    system("pause");
                    }
                else
                    {
                    printf("\nLa modificacion fue realizada correctamente\n");
                    system("pause");
                    }
            }
            break;

        case 3:
            //Elimina de manera logica al empleado por id colocando la variable "isEmpy" en 1
            system("cls");
            printf("\nIngrese legajo: ");
            scanf("%d",&id);
            id=validationId(id);
            end=removeEmployee(employee,LENGTHY,id);
            if(end==0)
                printf("\nLa baja se llevo a cabo correctamente\n");
            else
                printf("\nNo se pudo realizar la baja\n");
            system("pause");

            break;
        case 4:
            order=menuOfSort();
            end=sortEmployees(employee,LENGTHY,order,orderSector,LENGTHYSECTOR);
            if(end==0)
                printf("\nRetornando al menu anterior\n");
            else
                printf("Error");
            break;
        case 0:
            exit=1;
            break;
        default:
            printf("Esa opcion no existe, reingrese ");
            break;
        }
    }while(exit==0);
}


