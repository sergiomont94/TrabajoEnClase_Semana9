#include "Herramienta.h"
#include <iostream>
#include <fstream>

using namespace std;
// ifstream leer,seekg
//ofstream escribir,seekp

void crearArchivo() {
	ofstream ArchivoOutB("ferreteria.dat", ios::out | ios::binary | ios::app);

	if (!ArchivoOutB)
	{
		cout << "Error al abrir ferreteria.dat";
		return;
	}

	Herramienta blanco;

	for (int i = 0; i < 100; i++)
	{
		ArchivoOutB.write(reinterpret_cast<const char*>(&blanco), sizeof(Herramienta));
	}
	cout << "Archivo creado!";
	ArchivoOutB.close();
}

void registrarHerramienta() {
	ofstream ArchivoOut("ferreteria.dat", ios::out | ios::binary | ios::app);

	if (!ArchivoOut)
	{
		cout << "Error al abrir ferreteria.dat ";
		return;
	}

	ArchivoOut.seekp(0, ios::beg);

	cout << "\n\n == Registro de herramientas ==\n\n";

	int opc = 0;

	do
	{
		Herramienta nueva;
		cout << "Ingrese codigo: " << endl;
		cin >> nueva.codigo;

		cout << "Ingrese nombre: " << endl;
		cin >> nueva.nombre;

		cout << "Ingrese cantidad: " << endl;
		cin >> nueva.cantidad;

		cout << "Ingrese precio: " << endl;
		cin >> nueva.precio;

		ArchivoOut.write(reinterpret_cast<const char*>(&nueva), sizeof(Herramienta));

		cout << "Se guardo la herramienta"<<endl;

		cout << "Desea agregar otra herramienta?(1 para SI o -1 para NO)" << endl;
		cin >> opc;


	} while (opc != -1);
	ArchivoOut.close();


}

void imprimirHerramienta() {
	ifstream archivoIn("ferreteria.dat", ios::in | ios::binary);

	if (!archivoIn)
	{
		cout << "Error al abrir ferreteria.dat";
		return;
	}

	//archivoIn.seekg(0, ios::beg);
	archivoIn.seekg(2 * sizeof(Herramienta));

	cout << "\n\n == Lista de herramientas == \n\n";
	
	Herramienta actual;

	archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));

	while (!archivoIn.eof())
	{
		cout << "Codigo: " << actual.codigo << "\nNombre: " << actual.nombre << "\nCantidad: " << actual.cantidad << "\nPrecio: " << actual.precio << endl;
		cout << "--------------------------------------------"<<endl;
		archivoIn.read(reinterpret_cast<char*>(&actual), sizeof(Herramienta));
	}
	archivoIn.close();

}

void eliminarHerramienta(int cod) {
	ofstream archivoEli("ferreteria.dat", ios::out | ios::binary | ios::app);


	Herramienta elim;
	Herramienta *actual = new Herramienta();

	archivoEli.seekp((cod - 1) * sizeof(Herramienta), ios::beg);

	cout << "\n\n == Registro de herramientas ==\n\n";

	int opc = 0;

	do
	{
		Herramienta nueva;
		cout << "Ingrese nuevo codigo para actualizar o ingrese -1 para eliminar: " << endl;
		cin >> nueva.codigo;

		cout << "Ingrese nuevo nombre para actualizar o ingrese "" para eliminar: " << endl;
		cin >> nueva.nombre;

		cout << "Ingrese nueva cantidad para actualizar o ingrese -1 para eliminar: " << endl;
		cin >> nueva.cantidad;

		cout << "Ingrese nuevo precio para actualizar o ingrese -1 para eliminar: " << endl;
		cin >> nueva.precio;

		archivoEli.write(reinterpret_cast<const char*>(&nueva), sizeof(Herramienta));

		cout << "Se actualizo o elimino la herramienta" << endl;

		cout << "Desea actualizar/eliminar otra herramienta?(1 para SI o -1 para NO)" << endl;
		cin >> opc;


	} while (opc != -1);
	


}