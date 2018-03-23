#pragma once
#include <stdlib.h>
#include <string>
using namespace std;
#ifndef HERRAMIENTA_H
#define HERRAMIENTA_H


struct Herramienta {
	int codigo;//4 bytes
	char nombre[30];//30 bytes
	int cantidad;//4 bytes
	float precio;//4 bytes
	//42 bytes total
	Herramienta(){
		codigo = -1;
		strcpy_s(nombre, "");
		cantidad = -1;
		precio = -1;
	}
};

void crearArchivo();
void registrarHerramienta();
void imprimirHerramienta();
void eliminarHerramienta(int cod);
void buscarPos(int);





#endif // !HERRAMIENTA_H
