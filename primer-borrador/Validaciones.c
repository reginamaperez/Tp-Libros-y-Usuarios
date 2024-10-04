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
//3. VALIDAR MAIL
int validarMail (char mail[]){
 for(int i=0; i<strlen(mail); i++)
    {
        if(!isArroba(mail(i)) && !isPunt(i))
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

int esEmailValido(char email[])
{
    char * arroba;
    char * terminacion;

    arroba = strchr(email, '@');
    if (arroba == NULL) {
        return 0;  /// No tiene '@'
    }

    terminacion= strstr(email, ".com");
    if (terminacion == NULL || strcmp(terminacion, ".com") != 0) {
        return 0;  /// No tiene la terminaci�n '.com'
    }

    /// Asegurarse de que el '.com' est� despu�s del '@'
    if (arroba > terminacion) {
        return 0;
    }

    return 1;  // Cumple ambas condiciones
}


int validarMayusculaMinuscula(char contrasenia[]) {
    int tieneMayuscula = 0;
    int tieneMinuscula = 0;

    for (int i = 0; contrasenia[i] != '\0'; i++) {
        if (isupper(contrasenia[i])) {
            tieneMayuscula = 1;
        }
        if (islower(contrasenia[i])) {
            tieneMinuscula = 1;
        }
    }

    /// Devuelve 1 si ambas condiciones se cumplen, 0 de lo contrario
    return tieneMayuscula && tieneMinuscula;
}

//6. ENCONTRAR USUARIO
int encontrarUsuario (nodoUsuario* usu, char nombre[], char contra[]){
nodoUsuario* aux=usu;
int flag=0;
while (usu->sig!=NULL && flag==0){
    if (strcmp(nombre,aux->stUsuario.username)==0)
        flag=contrastarContra(aux, contra);
    else
    aux=aux->sig;
return flag;
}
}
//7.COMPARA CONTRASEÑA
int contrastarContra (nodoUsuario* aux, char contra[]){
if (strcmp(aux.>stUsuario.password,contra)==0)
    return 2;
else
    return 1;
}
