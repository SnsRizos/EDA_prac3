/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092
*/

#ifndef EVENTO_HPP
#define EVENTO_HPP

#include<iostream>
using namespace std;

// PREDECLARACION DEL TAD evento (inicio INTERFAZ)

/* Los valores del TAD evento representarán tuplas formadas como:
 (descripción, prioridad) siendo la descripción una cadena y la prioridad un número natural.}
*/
struct evento;
/* Dada una cadena nombre, un entero cantidad, 
devuelve un producto p con esos datos. 
*/
void crearEvento(string descrip,int prio, evento& e);

/* Dado un producto p, devuelve la cadena correspondiente al nombre de p. 
*/
string descripcion(const evento& e);

/* Dado un producto p, devuelve el entero correspondiente cantidad de p. 
*/
void cambiarDescripcion( evento& e,string nuevo);

/* Devuelve verdad si y sólo si los productos p1 y p2 tienen el mismo nombre. 
*/
int suPrioridad(const evento& e);
void cambiarPrioridad(evento& e, int pri); 


// FIN de la PREDECLARACION DEL TAD producto (fin INTERFAZ)

// DECLARACION DEL TAD producto
struct evento {
  	friend void crearEvento(string descrip,int prio, evento& e);
  	friend string descripcion(const evento& e);
  	friend void cambiarDescripcion( evento& e,string nuevo);
  	friend int suPrioridad(const evento& e);
	friend void cambiarPrioridad(evento& e, int pri); 
  private:  //declaracion de la representacion interna del tipo
            //... a completar COMPLETAR CON documentacion sobre la representacion interna ...
    string descrip;
    int prio;
};


#endif