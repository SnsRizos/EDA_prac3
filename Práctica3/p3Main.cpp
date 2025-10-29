#include "colecInterdep.hpp"
#include "evento.hpp"

#include <iostream>
#include <string>


int main(){
	evento e1, e2, e3, e4, e5;
	crearEvento("pepe",1, e1);
	string dato = descripcion(e1);
	cout << dato << endl;
	cambiarDescripcion(e1,"yets");
	dato = descripcion(e1);
	cout << dato << "\n\n";
	string id1 = "aaaa";
	crearEvento("nuevo",1, e2);
	crearEvento("dela",1, e3);
	crearEvento("todos",1, e4);
	crearEvento("fiji",1, e5);
	string id2 = "cccc";
	string id3 = "bbbb";

	colecInterdep<string,evento> bolsa;
	crear(bolsa);
	if(esVacia(bolsa)){
		cout << "yets\n";
	}
	cout << tamanyo(bolsa) << endl;
	anyadirIndependiente(bolsa,id1,e1);
	cout << tamanyo(bolsa) << endl;
	anyadirIndependiente(bolsa,id2,e2);
	anyadirDependiente(bolsa,id3,e2,id2);
	cout << tamanyo(bolsa) << endl;

	cout << obtenerSupervisor(id3, bolsa) << endl;

	if(existeDependiente(id1, bolsa)){
		cout << "Existe\n";
	}
	else{
		cout << "No existe\n";
	}
	cout << obtenerNumDependientes(id2, bolsa) << endl;
	hacerDependiente(bolsa, id1, id2);
	if(existeDependiente(id1, bolsa)){
		cout << "Existe\n";
	}
	else{
		cout << "No existe\n";
	}
	cout << obtenerNumDependientes(id2, bolsa) << endl;
	hacerIndependiente(bolsa, id1);
	if(existeDependiente(id1, bolsa)){
		cout << "Existe\n";
	}
	else{
		cout << "No existe\n";
	}
	cout << obtenerNumDependientes(id2, bolsa) << endl;

	if(existe(id3,bolsa)){
		cout << "Existe id\n";
	}
	else{
		cout << "No existe id\n";
	}
	borrar(id3,bolsa);

	cout << obtenerNumDependientes(id2, bolsa) << endl;

	if(existe(id3,bolsa)){
		cout << "Existe id\n";
	}
	else{
		cout << "No existe id\n";
	}

	if(!esVacia(bolsa)){
		cout << "notch\n";
	}
}