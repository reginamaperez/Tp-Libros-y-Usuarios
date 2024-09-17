#include "usuariosAdmin.h"

///ADMIN

/** Usando estructura:
typedef struct {
stUsuario datosUsuarios;
struct nodoUsuarios * sig;
}nodoUsuarios;
**/

/**
 PULIR:
- VALIDAR LONGITUD DE STRINGS EN MODIFICARUSUARIO
- AGREGAR FUNCION DE ID LIBRO A CARGARLIBROMANUAL

 FUNCIONES HECHAS:
- MOSTRAR DATOS DE 1 USUARIO
- MOSTRAR LISTA DE TODOS LOS USUARIOS (TODOS/SOLO ACTIVOS/INACTIVOS)
- BUSCAR USUARIO POR DNI Y MOSTRARLO
- BUSCAR USUARIO POR GMAIL Y MOSTRARLO
- DAR DE BAJA A UN USUARIO
- MODIFICAR DOMICILIO DE UN USUARIO (falta agregar validaciones de longitud del string)
- MODIFICAR USERNAME DE UN USUARIO (falta agregar validaciones de longitud del string)
**/

void mostrarUnUsuario(nodoUsuarios* usuario) ///No muestra todo los datos, como nacimento, solo los mas relevantes.
{
    if (usuario) {
        printf ("ID Usuario: %i", usuario->datosUsuarios.idUsuario);
        printf ("Username: %s\n", usuario->datosUsuarios.username);
        printf("Genero: %c\n", usuario->datosUsuarios.genero);
        printf("DNI: %s\n", usuario->datosUsuarios.dni);
        printf("Email: %s\n", usuario->datosUsuarios.email);
        printf("Domicilio: %s %d\n", usuario->datosUsuarios.domicilio.calle,usuario->datosUsuarios.domicilio.altura);
        printf("Localidad, CP, Ciudad: %s %i %s \n", usuario->datosUsuarios.domicilio.localidad, usuario->datosUsuarios.domicilio.cp, usuario->datosUsuarios.domicilio.ciudad);
        printf("País: %s\n", usuario->datosUsuarios.domicilio.pais);
        printf("Usuario activo?: %s\n", usuario->datosUsuarios.eliminado == 0 ? "Sí" : "No");
    }
}
/// Ver listado de todos los usuarios

void mostrarListaUsuarios (nodoUsuarios * listaUsuarios)
{
    while (listaUsuarios!=NULL)
    {
        mostrarUnUsuario (listaUsuarios);
        listaUsuarios = listaUsuarios->sig;
    }
}
/// Ver listado solo de usuarios activos

void mostrarListaUsuariosActivos (nodoUsuarios * listaUsuarios)
{
    while (listaUsuarios!=NULL)
    {
        if (listaUsuarios->datosUsuarios.eliminado == 0)
        {
          mostrarUnUsuario (listaUsuarios);
        }
        listaUsuarios = listaUsuarios->sig;
    }
}

/// Ver listado solo de usuarios inactivos
void mostrarListaUsuariosInactivos (nodoUsuarios * listaUsuarios)
{
    while (listaUsuarios!=NULL)
    {
        if (listaUsuarios->datosUsuarios.eliminado == -1)
        {
          mostrarUnUsuario (listaUsuarios);
        }
        listaUsuarios = listaUsuarios->sig;
    }
}
/// Opcion de que lista le interesa ver al admin

void elegirListaAVer (nodoUsuarios * listaUsuarios)
{
    char opcion;
    printf ("Elija lista a ver: A- Todos los usuarios B- Usuarios activos C- Usuarios Inactivos");
    fgets (opcion);

    if (opcion == 'A' || opcion == 'a')
    {
        mostrarListaUsuarios (listaUsuarios);
    }
    else if (opcion == 'B' || opcion == 'b')
    {
       mostrarListaUsuariosActivos (listaUsuarios);
    }
    else if (opcion == 'C' || opcion == 'c')
    {
     mostrarListaUsuariosInactivos (listaUsuarios);
    }
    else
    {
        printf ("\nOpcion invalida\n");
    }
}

/// Buscar Usuario por Dni o Email y mostrarlo

nodoUsuarios * buscarUsuarioPorDni(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;
    int encontrado=0;
    char buscarPorDni[20];
    printf("\n Ingrese numero de documento a buscar:\n");
    fflush (stdin);
    gets(buscarPorDni);

     while(aux!=NULL && encontrado == 0)
    {
            if(strcmp (aux->datosUsuarios.dni, buscarPorDni) == 0) ///datosUsuarios dentro de struct nodoUsuarios
            {
                encontrado = 1;
              mostrarUnUsuario (aux);
            }
            else
            {
                aux = aux->sig;
            }
        }
        if (encontrado == 0)
        {
            printf ("\nDni inexistente\n");
            aux = NULL;
        }

        return aux;
    }

/// Buscar Usuario por Email y mostrarlo

nodoUsuarios * buscarUsuarioPorEmail(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;
    int encontrado = 0;
    char buscarPorEmail[100];
    printf("\n Ingrese email a buscar:\n");
    fflush (stdin);
    gets (buscarPorEmail);

    while(aux!=NULL && encontrado == 0)
    {
            if (strcmpi(aux->datosUsuarios.email, buscarPorEmail) == 0) /// datosUsuarios: estructura para englobar datos del usuario dentro de struct nodoUsuarios
            {
                encontrado = 1;
               mostrarUnUsuario(aux);
            }
            else
            {
                aux = aux->sig;
            }
    }
        if (encontrado == 0)
        {
            printf ("\nEmail inexistente\n");
            aux = NULL;
        }
        return aux;
}
/// Baja lógica de un usuario
nodoUsuarios* bajaDelUsuario(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;

    if (listaUsuarios)
    {
        printf("\nBuscar usuario a modificar segun: A-DNI B- EMAIL\n");
        scanf ("%c",&opcion);
        if (opcion == 'A' || opcion == 'a')
        {
            aux = buscarUsuarioPorDni(listaUsuarios);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            aux = buscarUsuarioPorEmail(listaUsuarios);
        }
        else
        {
            printf ("\nOpcion invalida\n");
        }
    while (aux!=NULL)
    {
    
                aux->datosUsuarios.eliminado = -1;  /// Activo = 0, No Activo = -1

                printf("\nUsuario dado de baja exitosamente:\n");
               mostrarUnUsuario(aux);
            }
    }

    return listaUsuarios;
}
/// Modificar domicilio del usuario

nodoUsuarios * modificarDireccionUsuario(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = NULL;
    char opcion;
    char cambios[100]; /// misma variable para cambios de calle, ciudad, pais y localidad
    int nuevoNumero; /// usaré una misma variable para el cambio altura como para CP

    if (listaUsuarios)
    {
        ("\nBuscar usuario a modificar segun: A-DNI B- EMAIL\n");
        scanf ("%c",&opcion);
        if (opcion == 'A' || opcion == 'a')
        {
            aux = buscarUsuarioPorDni(listaUsuarios);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            aux = buscarUsuarioPorEmail(listaUsuarios);
        }
        else
        {
            printf ("\nOpcion invalida\n");
        }
        if (aux!=NULL)
        {
            printf ("\nDesea modificar domicilio del usuario? s/n\n");
        scanf ("%c",&opcion);
        if (opcion == s || opcion == S)
        {
          printf ("\nIngrese nueva calle:\n");
          gets (cambios);
          strcpy(aux->datosUsuarios.domicilio.calle, cambios);

           printf ("\nIngrese nueva altura:\n");
           fflush (stdin);
          scanf ("%i", &nuevoNumero);
          aux->datosUsuarios.domicilio.altura = nuevoNumero;

           printf ("\nIngrese nuevo codigo postal:\n");
           fflush (stdin);
          scanf ("%i", &nuevoNumero);
          aux->datosUsuarios.domicilio.cp = nuevoNumero;

           printf ("\nIngrese nueva localidad\n:");
          gets (cambios);
          strcpy(aux->datosUsuarios.domicilio.localidad, cambios);

             printf ("\nIngrese ciudad:\n");
          gets (cambios);
          strcpy(aux->datosUsuarios.domicilio.ciudad, cambios);
        }

         printf ("\nDesea modificar el pais? s/n\n");
         scanf ("%c",&opcion);
        if (opcion == s || opcion == S)
        {
           printf ("\nIngrese nuevo pais:\n");
          gets (cambios);
          strcpy(aux->datosUsuarios.domicilio.pais, cambios);
        }
        printf ("\nUsuario modificado:\n");
        mostrarUnUsuario (aux);
    }
    }
    return listaUsuarios;
}

/// Modificar usernme de un usuario

nodoUsuarios * modificarUsername (nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = NULL;
    char opcion;
    char nuevoUser[20];

    if (listaUsuarios)
    {
       ("\nBuscar usuario a modificar segun: A-DNI B- EMAIL\n");
        scanf ("%c",&opcion);
        if (opcion == 'A' || opcion == 'a')
        {
            aux = buscarUsuarioPorDni(listaUsuarios);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            aux = buscarUsuarioPorEmail(listaUsuarios);
        }
        else
        {
            printf ("\nOpcion invalida\n");
        }

        if (aux!=NULL)
        {

        printf ("\nIngrese el nuevo Username:\n");
        fflush (stdin);
        gets (nuevoUser);
        strcpy(aux->datosUsuarios.username, nuevoUser);
        }

        printf ("\nUsuario modificado:\n");
        mostrarUnUsuario (aux);
    }
    return listaUsuarios;
}
