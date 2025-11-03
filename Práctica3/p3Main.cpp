/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092*/
#include "colecInterdep.hpp"
#include "evento.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>

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
					anyadirDependiente(lista,ident,v,super); //Mirar haber como hacer que se sepa si se ha introducido o no
				}else if(dependencia =="INDependiente"){
					anyadirIndependiente(lista,ident,v);
				}
				ofstream s;
				s.open("salida.txt");
				if(s.is_open()){
					if(existe(ident,lista)){
						s<<"INTRODUCIDO: ";

					}else{
						s<<"NO INTRODUCIDO: ";

					}
						if(dependencia == "INDependiente"){
							s<<"[ "<<ident<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
						}else{
							s<<"[ "<<ident<<"-de-> "<<super<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}

				}else{
					cerr << "No ha podido escribirse el fichero \"" << "salida.txt" << "\"." << endl;
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
			}else if( instruccion == "O"){//MUESTRA TODA LA INFORMACION  DE ESE ID
				f >> ident;
				getline(f,salto);
				obtenerVal(ident,lista,v);//Mirar si necesita un aviso si funciona mal
				info=descripcion(v);
				prioridad=suPrioridad(v);
				obtenerSupervisor(ident,lista,super);
				obtenerNumDependientes(ident,lista);
				//Añadir para escribir en fichero de salida	
			}else if(instruccion == "E"){//BUSCA SI EXISTE ESE IDENT
				f >> ident;
				getline(f,salto);
				existe(ident,lista); 
				//Añadir para escribir en fichero de salida
			}else if(instruccion =="I"){//HACE INDEPENDIENTE A ESE IDENT
				f >> ident;
				getline(f,salto);
				hacerIndependiente(lista,ident);
				//Añadir para escribir en fichero de salida
			}else if(instruccion == "D"){//HACE DEPENDIENTE AL IDENT DE NUEVO
				f >> ident;
				getline(f,salto);
				f >> super;
				getline(f,salto);
				hacerDependiente(lista,ident,super);
				//Añadir para escribir en fichero de salida
			}else if (instruccion == "B"){//BORRA DE LA COLECCION EL ID
				f >> ident;
				getline(f,salto);
				borrar(ident,lista);
				//Añadir para escribir en fichero de salida
			}else if ( instruccion == "LD"){//RECORRER TODA LA LISTA CON EL ITERADOR Y CUANDO UNO DEPENDA DEL SUPER QUE NOS DEN IMPRIMIR SUS DATOS
				f >> super;
				getline(f,salto);
				iniciarIterador(lista);
				int puesto= 1;
				while(existeSiguiente(lista)){
						if(siguienteDependiente(lista)){
							if(siguienteSuperior(lista,ident)){
								
								//Falta el OFSTREAM que muestra los datos

							}



						}
					avanza(lista);

				}
				
				
			}else if( instruccion == "LT"){//RECORRER TODO LA LISTA MOSTRANDO TODOS LOS DATOS DE TODA LA LISTA
					iniciarIterador(lista);


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
	string super;

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

	cout << obtenerSupervisor(id3, bolsa,super) << endl;//Modificado por Mijayl

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