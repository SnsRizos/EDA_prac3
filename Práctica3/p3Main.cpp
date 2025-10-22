#include "colecInterdep.hpp"
#include "evento.hpp"

#include <iostream>


int main(){
	evento e1;
	crearEvento("pepe",1, e1);
	string dato = descripcion(e1);
	cout << dato << endl;
	cambiarDescripcion(e1,"yets");
	dato = descripcion(e1);
	cout << dato << endl;
	
}