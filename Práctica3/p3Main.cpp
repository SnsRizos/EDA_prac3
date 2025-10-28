#include "colecInterdep.hpp"
#include "evento.hpp"

#include <iostream>
#include <string>


int main(){
	evento e1;
	crearEvento("pepe",1, e1);
	string dato = descripcion(e1);
	cout << dato << endl;
	cambiarDescripcion(e1,"yets");
	dato = descripcion(e1);
	cout << dato << "\n\n";
	string id1 = "aaa";
	
	colecInterdep<string,evento> bolsa;
	crear(bolsa);
	if(esVacia(bolsa)){
		cout << "yets\n";
	}
	cout << tamanyo(bolsa) << endl;
	anyadirIndependiente(bolsa,id1,e1);
	cout << tamanyo(bolsa) << endl;
}