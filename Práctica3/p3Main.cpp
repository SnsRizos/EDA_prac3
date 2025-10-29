/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092*/
#include "colecInterdep.hpp"
#include "evento.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void leerInstrucciones(colecInterdep<string,evento>lista){
	ifstream f;
	f.open("entrada.txt");

	if(f.is_open()){
		evento v;
		string instruccion,salto;
		string ident;
		string info;
		int    prioridad;
		string dependencia;
		string super;

		while(f >> instruccion){
			getline(f,salto);
			
			if(instruccion == "A"){//AÑADE UN NUEVO ID A LA MEMORIA

				f >> ident; //HAY QUE CAMBIARLO
				getline(f,salto);
				f >> info; //HAY QUE CAMBIARLO
				getline(f,salto);
				f >> prioridad; //HAY QUE CAMBIARLO
				getline(f,salto);
				f >> dependencia; //Posiblemente
				getline(f,salto);
				f >> super;//Sera un string que si es Dependiente tendra que hacer un atoi
				getline(f,salto);
				crearEvento(info,prioridad,v);
				if(dependencia == "DEPendiente"){ 
					anyadirDependiente(lista,ident,v,super); 
				}else{
					anyadirIndependiente(lista,ident,v);
				}
				//Añadir para escribir en fichero de salida
			}else if( instruccion == "C"){ // CAMBIA EL VALOR DEL ID QUE NOS DA 
				
			
				f >> ident;
				getline(f,salto);
				f >> info;
				getline(f,salto);
				f >> prioridad;
				getline(f,salto);
				crearEvento(info,prioridad,v);
				actualizarVal(lista,ident,v); 
				//Añadir para escribir en fichero de salida
			}else if( instruccion == "O"){//MUESTRA TODA LA INFORMACION DEL EVENTO DE ESE ID
				f >> ident;
				getline(f,salto);
				v=obtenerVal(ident,lista);
				info=descripcion(v);
				prioridad=suPrioridad(v);
				//Añadir para escribir en fichero de salida	
			}else if(instruccion == "E"){//BUSCA SI EXISTE ESE IDENT
				f >> ident;
				getline(f,salto);
				existe(ident); //HAY QUE AÑADIR VARIABLES

			}else if(instruccion =="I"){//HACE INDEPENDIENTE A ESE IDENT
				f >> ident;
				getline(f,salto);
				hacerIndependiente(ident);//HAY QUE AÑADIR VARIABLES

			}else if(instruccion == "D"){//HACE DEPENDIENTE AL IDENT DE NUEVO
				f >> ident;
				getline(f,salto);
				string nuevo;
				f >> nuevo;
				getline(f,salto);
				hacerDependiente(,ident,nuevo);//HAY QUE AÑADIR VARIABLES
			}else if (instruccion == "B"){//BORRA DE LA COLECCION EL ID
				f >> ident;
				getline(f,salto);
				borrar(ident);//HAY QUE AÑADIR VARIABLES
			}else if ( instruccion == "LD"){
				f >> ident ;
				
			}

		}

	}

}



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