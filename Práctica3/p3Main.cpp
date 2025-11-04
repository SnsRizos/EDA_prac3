/* Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926092*/
#include "colecInterdep.hpp"
#include "evento.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void leerInstrucciones(colecInterdep<string,evento>colec){
	ifstream f;
	f.open("entrada.txt");

	if(f.is_open()){
		ofstream s;
			s.open("salida.txt");
			if(s.is_open()){
			evento v;
			string instruccion,salto;
			string ident;
			string info;
			int    prioridad;
			string dependencia;
			string super;
			int numDepends;//Si da problemas alguna funcion darle a esto valor 0 al principio

			while(f >> instruccion){
			getline(f,salto);
			
			if(instruccion == "A"){//AÑADE UN NUEVO ID A LA MEMORIA

				f >> ident; 
				getline(f,salto);
				f >> info; 
				getline(f,salto);
				f >> prioridad; 
				getline(f,salto);
				f >> dependencia;
				getline(f,salto);
				f >> super;
				getline(f,salto);
				crearEvento(info,prioridad,v);
				if(dependencia == "DEPendiente"){ 
					anyadirDependiente(colec,ident,v,super); 
				}else if(dependencia =="INDependiente"){
					anyadirIndependiente(colec,ident,v);
				}
				
				if(existe(ident,colec)){
					s <<"INTRODUCIDO: ";
				}else{
					s <<"NO INTRODUCIDO: ";
				}
				if(dependencia == "INDependiente"){
					s <<"[ "<<ident<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
				}else if(dependencia =="INDependiente"){
					s <<"[ "<<ident<<"-de-> "<<super<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
				}
						
				
			}else if( instruccion == "C"){ // CAMBIA EL VALOR DEL ID QUE NOS DA 
				f >> ident;
				getline(f,salto);
				f >> info;
				getline(f,salto);
				f >> prioridad;
				getline(f,salto);
				crearEvento(info,prioridad,v);
				
					if(actualizarVal(colec,ident,v)){
						s <<"CAMBIADO: ";
						numDepends =obtenerNumDependientes(ident,colec);
						if(existeIndependiente(ident,colec)){
							s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}else{
							obtenerSupervisor(ident,colec,super);
							s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<	numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}
					}else{
						s <<"NO CAMBIADO: "<< ident<<endl;
					}
			}else if( instruccion == "O"){//MUESTRA TODA LA INFORMACION  DE ESE ID
				f >> ident;
				getline(f,salto);
	
				if(obtenerVal(ident,colec,v)){
					s <<"LOCALIZADO: ";
					info=descripcion(v);
					prioridad=suPrioridad(v);
					numDepends =obtenerNumDependientes(ident,colec);
					if(existeIndependiente(ident,colec)){
						s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

					}else{
						obtenerSupervisor(ident,colec,super);
						s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;
					}
				}else{
					s <<"NO LOCALIZADO: "<<ident<<endl;

				}
			}else if(instruccion == "E"){//BUSCA SI EXISTE ESE IDENT
				f >> ident;
				getline(f,salto);

				if(existe(ident,colec)){
					if(existeIndependiente(ident,colec)){
						s <<"INDEPendiente: ";
					}else{
						s <<"DEPendiente: ";
					}
				}else{
					s <<"DESCONOCIDO: ";

				} 
				s <<ident<<endl;
			
			}else if(instruccion =="I"){//HACE INDEPENDIENTE A ESE IDENT
				f >> ident;
				getline(f,salto);
			
				if(existe(ident,colec)){
					if(existeIndependiente(ident,colec)){
						s <<"YA ERA INDepend.: ";
					}else{
						hacerIndependiente(colec,ident);
						s <<"INDEPENDIZADO: ";
					}
					}else{
						s <<"NO INDEPENDIZADO: ";

					} 
					s <<ident<<endl;
			}else if(instruccion == "D"){//HACE DEPENDIENTE AL IDENT DE SUPER
				f >> ident;
				getline(f,salto);
				f >> super;
				getline(f,salto);
				
				if(existe(ident,colec) && existe(super,colec)){
						
					hacerDependiente(colec,ident,super);
					s <<"INTENTANDO hacer depend.: ";
						
				}else{
					s <<"IMPOSIBLE hacer depend.: ";

				} 
				s <<ident<<" -de-> "<<super<<endl;
			}else if (instruccion == "B"){//BORRA DE LA COLECCION EL ID
				f >> ident;
				getline(f,salto);
				borrar(ident,colec);

				if(!existe(ident,colec)){
					s <<"BORRADO: ";
						
				}else{
					s <<"NO BORRADO: ";

				} 
				s <<ident<<endl;	
			}else if ( instruccion == "LD"){//RECORRER TODA LA colec CON EL ITERADOR Y CUANDO UNO DEPENDA DEL SUPER QUE NOS DEN IMPRIMIR SUS DATOS
				f >> ident;
				getline(f,salto);
				
				if(existe(ident,colec)){
					s <<"****DEPENDIENTES: "<<ident<<endl;
					obtenerVal(ident,colec,v);
					info=descripcion(v);
					prioridad=suPrioridad(v);
					numDepends =obtenerNumDependientes(ident,colec);

					if(existeIndependiente(ident,colec)){
						s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" ) ****"<<endl;
					}else{
						obtenerSupervisor(ident,colec,super);
						s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" ) ****"<<endl;
					}
					iniciarIterador(colec);
					int puesto= 1;
					string iddep;

					while(existeSiguiente(colec)){ // Si eso modificar con puesto menor cuando vaya LD porque si no hay dependientes de ident recorre de todas maneras la colec
						
						if(siguienteSuperior(colec,super)){
							
								if(super == ident){
									siguienteIdent(colec,iddep);
									siguienteVal(colec,v);
									info=descripcion(v);
									prioridad=suPrioridad(v);
									numDepends=siguienteNumDependientes(colec);
									s <<"["<<puesto<<" -> "<<iddep<<" -de-> "<<ident<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" ) ;;;;"<<endl;
									puesto++;
								}
								

						}
						avanza(colec);

					}
					s <<"****FINAL dependientes -de-> "<<ident<<endl;
				}else{
					s <<"****DESCONOCIDO"<<endl;
				}
				
			}else if( instruccion == "LT"){//RECORRER TODO LA colec MOSTRANDO TODOS LOS DATOS DE TODA LA colec
				s <<"-----LISTADO: "<<tamanyo(colec)<<endl;
				
				if(tamanyo>0){
					iniciarIterador(colec);
					
					while(existeSiguiente(colec)){ // Si eso modificar con puesto menor cuando vaya LD porque si no hay dependientes de ident recorre de todas maneras la colec
						siguienteIdent(colec,ident);
						siguienteVal(colec,v);
						info=descripcion(v);
						prioridad=suPrioridad(v);
						numDepends=siguienteNumDependientes(colec);

						if(siguienteSuperior(colec,super)){
									
							s <<"[ "<<ident<<" -de-> "<<super<<" ;;; "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;

						}else{
							s <<"[ "<<ident<<" --- "<<numDepends<<" ] --- "<<info<<" --- ( "<<prioridad<<" )"<<endl;		
						}
						avanza(colec);

					}
				}
				s <<"-----"<<endl;
			}

		}
		s.close();
	}else{
			cerr << "No ha podido escribirse el fichero \"" << "salida.txt" << "\"." << endl;
		}
		f.close();
	}else{
			cerr << "No ha podido leer el fichero \"" << "entrada.txt" << "\"." <<endl;
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