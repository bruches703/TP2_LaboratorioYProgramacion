#ifndef funtions
#define funtions

#define LENGTHY 100
#define LONGNAME 51
#define LENGTHYSECTOR 3

typedef struct
{
    int id;
    char name[LONGNAME];
    char lastName[LONGNAME];
    float salary;
    int sector;
    int isEmpy;

}Employee;


int addEmployee(Employee employee[], int len, int id, int index, char name[],char lastName[],float salary,int sector);
int initEmployee(Employee employee[], int len);
int initSector(int sectors[],int len);
int findEmployeeById(Employee employee[], int len, int id);
int menu (void);
int menuOfSort (void);
int modifyEmployee (Employee employee[], int len,int file);
int printEmployee (Employee employee);
int printSector(int sector[], int len);
int removeEmployee(Employee employee[], int len, int id);
int searchFree(Employee employee[], int len);
int sortEmployees(Employee employee[],int len, int order, int sector[], int lenSector);




#endif // funtions
