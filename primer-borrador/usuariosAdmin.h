#ifndef USUARIOSADMIN_H_INCLUDED
#define USUARIOSADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"

typedef struct{
char calle[50];
int altura;
int cp;
char ciudad[100];
char localidad[50];
char pais[100];
} stDomicilio;

typedef struct{
int idUsuario;
char email[100];
char password[20];
char username[20];
int esAdmin; /// 1 = si 0 = no
char genero;
char fechaNacimiento[20]; /// o se puede hacer con dia, mes, anio.
int librosFavoritos[50]; /// se van a guardar los id de los libros favs.
int validosLibrosFavs;
char dni[10];
stDomicilio domicilio;
int eliminado; /// 0 si está activo - 1 si está eliminado
}stUsuario;

typedef struct {
stUsuario datosUsuarios;
struct nodoUsuarios * sig;
}nodoUsuarios;

///Prototipados
nodoUsuarios * buscarUsuarioPorDni(nodoUsuarios * listaUsuarios);
nodoUsuarios * buscarUsuarioPorEmail(nodoUsuarios * listaUsuarios);
nodoUsuarios* bajaDelUsuario(nodoUsuarios * listaUsuarios);
nodoUsuarios * modificarDireccionUsuario(nodoUsuarios * listaUsuarios);
nodoUsuarios * modificarUsername (nodoUsuarios * listaUsuarios);
void mostrarUnUsuario(nodoUsuarios* usuario);
void mostrarListaUsuariosInactivos (nodoUsuarios * listaUsuarios);
void mostrarListaUsuariosActivos (nodoUsuarios * listaUsuarios);
void mostrarListaUsuarios (nodoUsuarios * listaUsuarios);
void elegirListaAVer (nodoUsuarios * listaUsuarios);
#endif // USUARIOSADMIN_H_INCLUDED
