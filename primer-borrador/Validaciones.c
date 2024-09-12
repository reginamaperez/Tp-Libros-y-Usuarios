#include "Validaciones.h"

int validarStringNombre(char username[])
{
    for(int i=0; i<strlen(username); i++)
    {
        if(!isalpha(username[i]) && !isspace(username[i]))
        {
            return 0;
        }
    }
    return 1;
}
//2. VALIDAR STRING NUM
int validarStringNum(char username[])
{
    for(int i=0; i<strlen(username); i++)
    {
        if(!isdigit(username[i]))
        {
            return 0;
        }
    }
    return 1;
}


//4. VALIDAR LENGHT DE LA CONTRASENIA
int validarLenghtContrasenia(char password[])
{
    if(strlen(password)<5)
    {
        return 0;
    }
    return 1;
}
//5. VALIDAR CONTRASENIA
int validarContrasenia(char password[], char password1[])
{
    if(strcmp(password, password1)==0)
    {
        return 1;
    }
    return 0;
}
