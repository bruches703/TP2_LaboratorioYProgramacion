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
int addEmployee(Employee employee[], int len, int id, int index, char name[],char lastName[],float salary,int sector);


/** \brief Indicates all the positions of the array of employees that is free, the function puts the flag "isEmpy" in 1 (TRUE) in all positions of the array
 *
 * \param Employee structure array
 * \param Size of the structure array "employee"
 * \return Returns -1 for an error or 0 if the function was carried out correctly
 */
int initEmployee(Employee employee[], int len);

/** \brief Initializes the sector array "sectors". Give value 1 the first position of the array and increase in the next position to the maximum value
 *
 * \param Array of sectors integers
 * \param Size of the array "sectors"
 * \return Returns 0 if the function was carried out correctly
 */
int initSector(int sectors[],int len);


/** \brief Search if the id is occupied by another employee in the array
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \return Returns index of the position of the array free
 */
int findEmployeeById(Employee employee[], int len, int id);

/** \brief Function printing ABM options menu
 *
 * \return Returns -1 if the function fails or returns the integer value of the chosen option (from 0 to 4)
 */
int menu (void);


/** \brief Submenu, ordering
 *
 * \return Returns -1 if the function failed or returns the integer of the option chosee
 */
int menuOfSort (void);

/** \brief Modify the name, last name, salary or sector of the employee array
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \param Stored the ID of the employee
 * \return returns 1 if the function was carried out correctly, or returns -1 if failed
 */
int modifyEmployee (Employee employee[], int len,int file);


/** \brief Show of data of an employee
 *
 * \param Receives a position of the employee array
 * \return Returns 0 if the function was carried out correctly
 */
int printEmployee (Employee employee);

/** \brief Show list of the sectors
 *
 * \param Array of integers of sectors
 * \param Integer value of the employee array length
 * \return Returns the auxiliary whit the value save of the sector
 */
int printSector(int sector[], int len);

/** \brief Delete employee by id putting the variable "isEmpy" in value 1.
 *
 * \param Array of strut of employee.
 * \param Integer value of the employee array length.
 * \param Id of the employee to delete.
 * \return Returns 0 if the function was carried out correctly, or -1 if the function failed.
 */
int removeEmployee(Employee employee[], int len, int id);

/** \brief Search in the array of the employee structure for the first free position, looking for the variable "isEmpy" in 0
 *
 * \param Array of strut of employee
 * \param Integer value of the employee array length
 * \return Returns index of the position of the array free
 */
int searchFree(Employee employee[], int len);


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
int sortEmployees(Employee employee[],int len, int order, int sector[], int lenSector);




#endif // funtions
