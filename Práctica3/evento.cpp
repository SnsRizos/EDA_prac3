/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092
*/
#include <iostream>
#include "evento.hpp"

using namespace std;

void crearEvento(string descrip,int prio, evento& e){
	e.descrip=descrip;
	e.prio=prio;

}

string descripcion(const evento& e){

	return e.descrip;

}


void cambiarDescripcion( evento& e,string nuevo){

	e.descrip=nuevo;

}

int suPrioridad(const evento& e){

	return e.prio;
}

void cambiarPrioridad(evento& e, int newpri){

	e.prio=newpri;

}