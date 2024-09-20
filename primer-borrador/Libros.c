#include "Libros.h"

/** Usando estructura:

typedef struct {
stLibro datosLibros;
struct nodoLibros * sig;
}nodoLibros;
-----------------------------------------------------
typedef struct{
int idLibro; /// único, autoincremental
char titulo[100];
char editorial[50];
char autor[50];
char categoria[50];
float valoracion;
int eliminado; /// 0 si está activo - 1 si está eliminado
}stLibro;
**/

/// Cargar un libro

nodoLibros * cargarUnLibroManual (nodoLibros * listaLibros)
{
    nodoLibros * nuevoLibro = listaLibros;
    char camposLibro[50];
    char tituloLibro[100];

    printf ("\nTitulo del libro: \n");
    fflush (stdin);
    gets (tituloLibro);
    strcpy(nuevoLibro->datosLibros.titulo, tituloLibro);

    printf ("\nEditorial del libro: \n");
    fflush (stdin);
    gets (camposLibro);
    strcpy(nuevoLibro->datosLibros.editorial, camposLibro);

    printf ("\nAutor del libro: \n");
    fflush (stdin);
    gets (camposLibro);
    strcpy(nuevoLibro->datosLibros.autor, camposLibro);

    printf ("\nCategoria del libro: \n");
    fflush (stdin);
    gets(camposLibro);
    strcpy(nuevoLibro->datosLibros.categoria, camposLibro);

    nuevoLibro->datosLibros.valoracion = 0;
    nuevoLibro->datosLibros.eliminado = 0; /// Activacion del libro
    //nuevoLibro->datosLibros.idLibro =
    ///cuando se tenga funcion de generar ID.
     nuevoLibro->siguiente = NULL;

    agregarAlFinal (listaLibros, nuevoLibro);

    printf ("\nLibro agregado exitosamente!\n");

    return nuevoLibro;
}

///Carga un libro de forma automatica
nodoLibros* cargarLibroAutomatico (stLibro librin){
  nodoLibros* nuevoLibro=(nodoLibros*)malloc(sizeof(nodoLibros*));
  
    strcpy(nuevoLibro->datosLibros.titulo,librin.titulo);

    strcpy(nuevoLibro->datosLibros.editorial, librin.editorial);

    strcpy(nuevoLibro->datosLibros.autor, librin.autor);

    strcpy(nuevoLibro->datosLibros.categoria, librin.categoria);

    nuevoLibro->datosLibros.valoracion = librin.valoracion;
    nuevoLibro->datosLibros.eliminado = librin.eliminado; /// Activacion del libro
    //nuevoLibro->datosLibros.idLibro =
    ///cuando se tenga funcion de generar ID.
     nuevoLibro->siguiente = NULL;

     return nuevoLibro;
}

///Libros del Archivo a la lista
nodoLibros* ArchivoALibro(nodoLibros*lista){
FILE*buf1=fopen(libros.dat,"rb");
stLibro aux;
nodoLibros* nodito=lista;

if (buf1!=NULL){
    while (fread(&aux,sizeof(stLibro),1,buf1)!=0){
        nodito->sig=cargarLibroAutomatico(aux);
        nodito=nodito->sig;
    }
    fclose(buf1);
    }
    return lista;
}

/// Libro de la lista al Archivo
void libroAArchivo (nodoLibros * nuevoLibro)
{
FILE * archivoLibros;
archivoLibros = fopen (libros.dat, "ab");

nodoLibros* libro = cargarUnLibroManual(listaLibros);

    if (libro != NULL) {
        fwrite(&libro->datosLibros, sizeof(stLibro), 1, archivoLibros);
        free(libro);
    }

    fclose(archivoLibros);
}

/// Baja lógica de un libro

nodoLibros* bajaDelLibro(nodoLibros * listaLibros)
{
    nodoUsuarios * aux = listaLibros;

    if (listaUsuarios)
    {
        printf("\nBuscar libro a eliminar segun: A-AUTOR B- TITULO C- CATEGORIA\n");
        scanf ("%c",&opcion);
        if (opcion == 'A' || opcion == 'a')
        {
            aux = buscarLibroPorAutor(listaLibros);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            aux = buscarLibroPorTitulo(listaLibros);
        }
        else if (opcion == 'c' || opcion == 'C')
        {
            aux = buscarLibroPorCategoria(listaLibros);
        }
        else
        {
            printf ("\nOpcion invalida\n");
        }
    if(aux!=NULL)
    {
                aux->datosLibros.eliminado = -1;  /// Activo = 0, No Activo = -1

                printf("\nLibro dado de baja exitosamente:\n");
               mostrarUnLibro(aux);
    }

    return listaLibros;
}


void mostrarUnLibro(nodoLibros* listaLibros)
{
    if (listaLibros) {
        printf ("ID Libro: %i", listaLibros->datosLibros.idLibro);
        printf ("Titulo: %s\n", listaLibros->datosLibros.titulo);
        printf("Editorial: %s\n", listaLibros->datosLibros.editorial);
        printf("Autor: %s\n", listaLibros->datosLibros.autor);
        printf("Categoria: %s\n", listaLibros->datosLibros.categoria);
        printf("Valoracion: %f %d\n", listaLibros->datosLibros.valoracion);
        printf("Libro activo?: %i\n", listaLibros->datosLibros.eliminado == 0 ? "Sí" : "No");
    }
}

/// Ver listado de todos los libros

void mostrarListaLibros (nodoLibros * listaLibros)
{
    while (listaLibros)
    {
        mostrarUnLibro (listaLibros);
        listaLibros = listaLibros->sig;
    }
}

nodoLibros * buscarLibroPorAutor(nodoLibros * listaLibros)
{
    nodoLibros * aux = listaLibros;
    int encontrado=0;
    char buscarPorAutor[20];
    printf("\n Ingrese numero de documento a buscar:\n");
    fflush (stdin);
    gets(buscarPorAutor);

     while(aux!=NULL && encontrado == 0)
    {
            if(strcmp (aux->datosLibros.autor, buscarPorAutor) == 0)
            {
                encontrado = 1;
              mostrarUnLibro (aux);
            }
            else
            {
                aux = aux->sig;
            }
        }
        if (encontrado == 0)
        {
            printf ("\n Autor inexistente\n");
            aux = NULL;
        }

        return aux;
    }
