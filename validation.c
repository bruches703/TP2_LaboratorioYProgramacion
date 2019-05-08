#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/** \brief Validate a character like 's' or 'n'
 *
 * \param Character in lowercase
 * \return Returns validated character
 *
 */
char validationChar(char character)
{
    while(character!='s' && character!='n')
    {
        printf("Opcion incorrecta, reingrese s/n: ");
        fflush(stdin);
        scanf("%c",&character);
        character=tolower(character);
    }
    return character;
}

//--------------------------------------------------------------------------------------

/** \brief Validate ID in range 1000 to 1100
 *
 * \param ID to validate
 * \return Returns the validated ID
 *
 */

int validationId (int id)
{
    while(id<1000 || id>1100)
    {
        printf("Id incorrecta, reingrese valor entre 1000 y 1100: ");
        scanf("%d",&id);
    }
    return id;
}

//--------------------------------------------------------------------------------------

/** \brief Validate the options of the menu in range
 *
 * \param The value minimum of the range
 * \param The value maximum of the range
 * \return Returns the validated option value
 *
 */
int validationMenu(int option, int a, int b)
{
    while(option<a || option>b)
    {
        printf("Opcion inexistente, reingrese: ");
        scanf("%d",&option);
    }
    return option;
}

//--------------------------------------------------------------------------------------

/** \brief Validate floating number to be greater than 0
 *
 * \param Floating number to validate
 * \return Returns the floating number correctly
 */
float validationPositive (float number)
{
    while(number<0)
    {
        printf("El valor es negativo, no se puede ingresar. Reingresar: ");
        scanf("%f",&number);
    }
    return number;
}

//--------------------------------------------------------------------------------------

/** \brief Validate the sector for range
 *
 * \param Integer with the value of sector
 * \param The value minimum of the range
 * \param The value maximum of the range
 * \return Returns the validated sector value
 *
 */

int validationSector(int sector, int a, int b)
{
    while(sector<a || sector>b)
    {
        printf("El sector no existe, reingrese: ");
        scanf("%d",&sector);
    }

    return sector;
}

//--------------------------------------------------------------------------------------

/** \brief validates the character string by long
 *
 * \param String of characters
 * \param Lengthy of the string
 * \return Returns 0 if function was carried out correctly
 *
 */
int validationString(char name[], int len)
{
    while(strlen(name)>len)
    {
        printf("El nombre es demasiado largo, reingrese");
        fflush(stdin);
        scanf("%s",name);
    }
    return 0;
}

