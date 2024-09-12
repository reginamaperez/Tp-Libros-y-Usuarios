#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct{
    int idLibro; /// �nico, autoincremental
    char titulo[100];
    char editorial[50];
    char autor[50];
    char categoria[50];
    float valoracion;
    int eliminado; /// 0 si est� activo - 1 si est� eliminado
}stLibro;

///     FUNCIONES

///- AGREGAR LIBRO
///- CONSULTA LIBRO POR AUTOR
///- CONSULTA LIBRO POR CATEGORIA
///- BUSQUEDA LIBRO POR TITULO
///- BUSQUEDA LIBRO POR AUTOR


#endif // LIBROS_H_INCLUDED
