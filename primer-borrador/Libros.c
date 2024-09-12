#include "Libros.h"


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
