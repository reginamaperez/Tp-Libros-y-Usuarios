#include "usuariosAdmin.h"

///ADMIN

/** Usando estructura:
typedef struct {
stUsuario datosUsuarios;
struct nodoUsuarios * sig;
}nodoUsuarios;
**/

/** FUNCIONES HECHAS:
- MOSTRAR DATOS DE 1 USUARIO
- MOSTRAR LISTA DE TODOS LOS USUARIOS (TODOS/SOLO ACTIVOS/INACTIVOS)
- BUSCAR USUARIO POR DNI Y MOSTRARLO
- BUSCAR USUARIO POR GMAIL Y MOSTRARLO
- DAR DE BAJA A UN USUARIO
- MODIFICAR DOMICILIO DE UN USUARIO (falta agregar validaciones de longitud del string)
- MODIFICAR USERNAME DE UN USUARIO (falta agregar validaciones de longitud del string)
**/


nodoUsuarios * iniclista()
{
    return NULL;
}

void mostrarUnUsuario(nodoUsuarios* usuario) ///No muestra todo los datos, como nacimento, solo los mas relevantes.
{
    if (usuario)
    {
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
    int encontrado = 0;
    char bajaUsuario[50];

    while (aux!=NULL && encontrado)
    {
        printf("\nIngrese el nombre del usuario a dar de baja:\n");
        fflush(stdin);
        gets(bajaUsuario);

        if (strcmpi(aux->datosUsuarios.username, bajaUsuario) == 0)
        {
            encontrado = 1;
            aux->datosUsuarios.eliminado = -1;  /// Activo = 0, No Activo = -1

            printf("\nUsuario dado de baja exitosamente:\n");
            mostrarUnUsuario(aux);
        }
        else
        {
            aux = aux->sig;
        }
    }
    if (!encontrado)
    {
        printf("\nUsuario no encontrado\n");
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



///Usuario:

///Registro manual:

///Un usuario puede crear una cuenta, para este proceso de registro/onboarding se deben validar los siguientes
///campos: email y contraseña.
///El email debe contener un @ y un .com. Además se debe válidar que el email no este registrado previamente por otro usuario.
///La contraseña debe contener por lo menos 1 mayúscula y 1 minúscula.
///Al momento en que finaliza el proceso de registro, se lo debe redirigir a la pantalla de login.

///Un usuario debe poder ingresar al sistema con sus credenciales: email y contraseña. En caso de que el email no exista
///se le debe indicar que no existe usuario con esos datos. En caso de que la contraseña no sea correcta, se le debe indicar
/// que algunos de los campos son incorrectos.

///Un usuario una vez logueado en el sistema podrá modificar su información personal.

///Una opción de deslogueo para salir del sistema y que pueda ingresar con otra cuenta.

///Asimismo, además de las funcionalidades anteriores, un usuario administrador podrá:
///Ver todos los usuarios registrados en el sistema.
///Dar de baja de usuarios.


void registrarUsuario(nodoUsuarios * listaUsuarios)
{
    stUsuario usuario;
    char username[20];
    char email[100];
    char dni[10];
    int rta;
    int opcion = 0;

    do {
        printf("Ingrese su Nombre de Usuario:  \n");
        fflush(stdin);
        gets(username);
        rta = buscarUsuarioPorUsername(listaUsuarios, username);  // Implementar esta función

        if (rta == 1) {
            printf("El nombre de usuario ya existe.\n");
            printf("1. Intentar de nuevo\n");
            printf("2. Salir\n");
            printf("Elija una opción: ");
            scanf("%d", &opcion);

            if (opcion == 2) {
                printf("Registro cancelado.\n");
                return;  // Salimos de la función si elige salir
            }
        }

    } while (rta == 1);  // Repetir mientras el nombre de usuario exista

    do {
        printf("Ingrese su email:  \n");
        fflush(stdin);
        gets(email);
        rta = buscarUsuarioPorEmail(listaUsuarios, email);  // Implementar esta función

        if (rta == 1) {
            printf("El email ya se encuentra registrado.\n");
            printf("1. Intentar de nuevo\n");
            printf("2. Salir\n");
            printf("Elija una opción: ");
            scanf("%d", &opcion);

            if (opcion == 2) {
                printf("Registro cancelado.\n");
                return;  // Salimos de la función si elige salir
            }
        }

    } while (rta == 1);  // Repetir mientras el email exista

    printf("Ingrese su Contrasenia:  \n");
    fflush(stdin);
    gets(usuario.password);

    printf("Usuario registrado exitosamente!\n");

    nodoUsuarios * nuevoNodo = crearNodoUsuario(usuario);
    listaUsuarios = agregarUsuarioAlFinalLista(listaUsuarios, nuevoNodo);
}

stUsuario cargarContraseniaRegistro(stUsuario usuario)
{
    char contrasenia[30];
    char confirmacion[30];
    printf("Ingrese su nueva contrasenia:  \n");
    fflush(stdin);
    gets(contrasenia);

    printf("Vuelva a ingresar su contrasenia \n");
    fflush(stdin);
    gets(confirmacion);

    while(!validarContrasenia(contrasenia, confirmacion) || || !validarMayusculaMinuscula(contrasenia))
    {
         if (!validarContrasenia(contrasenia, confirmacion)) {
            printf("Las contrasenias no coinciden\n");
        } else if (!validarMayusculaMinuscula(contrasenia)) {
            printf("La contrasenia debe tener al menos una mayúscula y una minúscula\n");
        }

        printf("Ingrese su nueva contrasenia:  \n");
        fflush(stdin);
        gets(contrasenia);

        printf("Vuelva a ingresar su contrasenia \n");
        fflush(stdin);
        gets(confirmacion);
    }

    // Si todo está bien, se copia la contraseña al usuario
    strcpy(usuario.contrasenia, contrasenia);
    return usuario;
}
}
//2. CARGAR USUARIO PARA REGISTRO
stUsuario cargarUsuarioRegistro(int tipoUsuario)
{
    stUsuario usuario;
    usuario.id = generarId();
    usuario.tipo = tipoUsuario;
    usuario.baja = 0;


    printf("Nombre de Usuario: \n");
    fflush(stdin);
    gets(usuario.username);

    printf("Ingrese un email: \n");
    fflush(stdin);
    gets(usuario.email);

    if (!esEmailValido(usuario.email))
    {
        printf("Email inválido. Debe contener '@' y terminar en '.com'.\n");
    }

esEmailValido(usuario.email);

printf("Dni: \n");
fflush(stdin);
gets(usuario.dni);

printf("Genero: (Ingrese m, f o x) \n");
fflush(stdin);
scanf(" %c", &usuario.genero);
while((usuario.genero != 'm' && usuario.genero != 'f' && usuario.genero != 'x'))
{
    printf("Error. Ingrese m, f o x. \n");
    printf("Genero: \n");
    fflush(stdin);
    scanf("%c", &usuario.genero);
}

printf("Calle: \n");
fflush(stdin);
gets(usuario.domicilio.calle);

printf("Altura: \n");
scanf("%d",&usuario.domicilio.altura);

printf("Codigo Postal: \n");
scanf("%d",&usuario.domicilio.cp);

printf("Ciudad: \n");
fflush(stdin);
gets(usuario.domicilio.ciudad);

printf("Localidad: \n");
fflush(stdin);
gets(usuario.domicilio.localidad);

printf("Pais: \n");
fflush(stdin);
gets(usuario.domicilio.pais);

usuario = cargarContraseniaRegistro(usuario);
return usuario;
}

nodoUsuarios * crearNodoUsuario(stUsuario usuario)
{
    nodoUsuarios * aux= (nodoUsuarios*) malloc(sizeof(nodoUsuarios));
    aux->datosUsuarios= usuario;
    aux->sig=NULL;
    return aux;
}

nodoUsuarios * buscarUltimoNodoListaUsuarios(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux=listaUsuarios;

    while(aux->sig !=NULL)
    {
        aux=aux->sig;
    }
    return aux;
}

nodoUsuarios * agregarUsuarioAlFinalLista(nodoUsuarios * listaUsuarios, nodoUsuarios * nuevo)
{
    if(!listaUsuarios)
    {
        listaUsuarios=nuevo;
    }
    else
    {

        nodoUsuarios * aux= buscarUltimoNodoListaUsuarios(listaUsuarios);
        aux->sig=nuevo;
    }
    return listaUsuarios;
}
