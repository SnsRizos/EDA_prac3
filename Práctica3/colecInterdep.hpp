// Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029 
#ifndef COLECINTEDEP_HPP
#define COLECINTEDEP_HPP

// PREDECLARACION DEL TAD GENERICO colecInterdep (inicio INTERFAZ)

 /*El TAD GENERICO  colecInterdep su dominio de valores  seran de datos booleanos(bool) y datos naturales(int),además el parametro de tipo T tendra que tener  definidas las operaciones igual y anterior

  
 */

template<typename I,typename V> struct colecInterdep;


/* COMPLETAR LA DOCUMENTACION PUBLICA DE CADA OPERACION DEL TAD
*/

template<typename I,typename V> void crear(colecInterdep<I,V>& c);


template<typename I,typename V> int tamanyo(colecInterdep<I,V>& c);


template<typename I,typename V> bool esVacia(colecInterdep<I,V>& c);


template<typename I,typename V> bool existe(const I& id, colecInterdep<I,V>& c);


template<typename I,typename V> bool existeDependiente(const I& id, colecInterdep<I,V>& c);


template<typename I,typename V> bool existeIndependiente(const I& id, colecInterdep<I,V>& c);


template<typename I,typename V> void anyadirIndependiente(colecInterdep<I,V>& c, const I& id, const V& v);


template<typename I,typename V> void anyadirDependiente(colecInterdep<I,V>& c, const I& id, const V& v, const I& super);


template<typename I,typename V> void hacerDependiente(colecInterdep<I,V>& c, const I& id, const I& super);


template<typename I,typename V> void hacerIndependiente(colecInterdep<I,V>& c, const I& id);


template<typename I,typename V> void actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo);


template<typename I,typename V> V obtenerVal(const I& id, colecInterdep<I,V>& c);


template<typename I,typename V> I obtenerSupervisor(const I& id, colecInterdep<I,V>& c);


template<typename I,typename V> int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c);


template<typename I,typename V> void borrar(const I& id, colecInterdep<I,V>& c);






template<typename I,typename V> void iniciarIterador(colecInterdep<I,V>& c);
template<typename I,typename V> bool existeSiguiente(colecInterdep<I,V>& c);
template<typename I,typename V> I siguienteIdent(colecInterdep<I,V>& c);
template<typename I,typename V> V siguienteVal(colecInterdep<I,V>& c);
template<typename I,typename V> bool siguienteDependiente(colecInterdep<I,V>& c);
template<typename I,typename V> I siguienteSuperior(colecInterdep<I,V>& c);
template<typename I,typename V> int siguienteNumDependientes(colecInterdep<I,V>& c);
template<typename I,typename V> void avanza(colecInterdep<I,V>& c);



// DECLARACION DEL TAD GENERICO agrupacion

template<typename I,typename V>
struct colecInterdep{
    	friend void crear<I,V>(colecInterdep<I,V>& c);
    	friend int tamanyo<I,V>(colecInterdep<I,V>& c);
    	friend bool esVacia<I,V>(colecInterdep<I,V>& c);
    	friend bool existe<I,V>(const I& id, colecInterdep<I,V>& c);
    	friend bool existeDependiente<I,V>(const I& id, colecInterdep<I,V>& c);
	friend bool existeIndependiente<I,V>(const I& id, colecInterdep<I,V>& c);
	friend void anyadirIndependiente<I,V>(colecInterdep<I,V>& c, const I& id,const V& v);
	friend void anyadirDependiente<I,V>(colecInterdep<I,V>& c, const I& id, const V& v, const I& super);
	friend void hacerDependiente<I,V>(colecInterdep<I,V>& c,const I& id, const I& super);
	friend void hacerIndependiente<I,V>(colecInterdep<I,V>& c, const I& id);
	friend void actualizarVal<I,V>(colecInterdep<I,V>& c, const I& id, const V& v);
	friend V obtenerVal<I,V>(const I& id, colecInterdep<I,V>& c);
	friend I obtenerSupervisor<I,V>(const I& id, colecInterdep<I,V>& c);
	friend int obtenerNumDependientes<I,V>(const I& id, colecInterdep<I,V>& c);
	friend void borrar<I,V>(const I& id, colecInterdep<I,V>& c);

	friend void iniciarIterador<I,V>(colecInterdep<I,V>& c);
	friend bool existeSiguiente<I,V>(colecInterdep<I,V>& c);
	friend I siguienteIdent<I,V>(colecInterdep<I,V>& c);
	friend V siguienteVal<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteDependiente<I,V>(colecInterdep<I,V>& c);
	friend I siguienteSuperior<I,V>(colecInterdep<I,V>& c);
	friend int siguienteNumDependientes<I,V>(colecInterdep<I,V>& c);
	friend void avanza<I,V>(colecInterdep<I,V>& c);

    

  private: //declaracion de la representacion interna del tipo
           //... a COMPLETAR CON documentacion sobre la representacion interna ...
	struct Celda{
	I ident;
	V valor;
	Celda* dep;
	int numDepend;
	Celda* sig;
};


	Celda* prim;
	int tam;
    //COMPLETAR CAMPOS ITERADOR
	Celda* itr;
};



//OPERACIONES
template<typename I,typename V> 
void crear(colecInterdep<I,V>& c){
	c.tam=0;
	c.prim=nullptr;
	c.itr=nullptr;

}



template<typename I,typename V>
int tamanyo(colecInterdep<I,V>& c){
	return c.tam;

}



template<typename I,typename V>
bool esVacia(colecInterdep<I,V>& c){
	return tamanyo(c)==0;
}



template<typename I,typename V> 
bool existe(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>::Celda* pAux = c.prim;

    // Recorremos mientras no se acabe la lista y la clave actual sea menor que la buscada
    while (pAux != nullptr && pAux->ident < id) {
        pAux = pAux->sig;
    }

    if (pAux == nullptr) {
      	return false;
    } else {
        if (pAux-> ident == id) {
          
            return true;

	} else {

            return false;

        }
    }
}




template<typename I,typename V>
bool existeDependiente(const I& id, colecInterdep<I,V>& c){
	bool encontrado = false;
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux != nullptr && pAux -> ident == id && pAux -> dep != nullptr){
			encontrado = true;
	}
	return encontrado;
}




template<typename I,typename V>
bool existeIndependiente(const I& id, colecInterdep<I,V>& c){
	bool encontrado = false;
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux != nullptr && pAux -> ident == id && pAux -> dep == nullptr){
			encontrado = true;
	}
	return encontrado;
}




template<typename I,typename V>
void anyadirIndependiente(colecInterdep<I,V>& c, const I& id, const V& v){
	if(c.prim==nullptr){	//es vacia
		c.prim = new typename colecInterdep<I,V>::Celda;
		c.prim -> ident = id;
		c.prim -> valor = v;
		c.prim -> dep = nullptr;
		c.prim -> numDepend = 0;
		c.prim -> sig = nullptr;
		c.tam = 1;
	}
	else{
		if(c.prim -> ident > id){	//anyadir al principio
			typename colecInterdep<I,V>::Celda* pAux = c.prim;
			c.prim = new typename colecInterdep<I,V>::Celda;
			c.prim -> ident = id;
			c.prim -> valor = v;
			c.prim -> dep = nullptr;
			c.prim -> numDepend = 0;
			c.prim -> sig = pAux;
			c.tam++;
		}
		else{		//general (entre 2 interdep o al final)
			typename colecInterdep<I,V>::Celda* pAux = c.prim;
			while(pAux -> sig != nullptr && (pAux -> sig -> ident < id)){
				pAux = pAux -> sig;
			}
			if(pAux->sig == nullptr || pAux -> sig -> ident != id){ //Si no existe
				typename colecInterdep<I,V>::Celda* pNuevo;
				pNuevo = new typename colecInterdep<I,V>::Celda;
				pNuevo -> ident = id;
				pNuevo -> valor = v;
				pNuevo -> dep = nullptr;
				pNuevo -> numDepend = 0;
				pNuevo -> sig = pAux -> sig;
				pAux -> sig = pNuevo;
				c.tam++;		
			}
		}
	}
}




template<typename I,typename V>
void anyadirDependiente(colecInterdep<I,V>& c, const I& id, const V& v, const I& super){
	if(!esVacia(c)){	
		if(c.prim -> ident > id){	//anyadir al principio
			typename colecInterdep<I,V>::Celda* pSup = c.prim;
			while(pSup != nullptr && pSup -> ident < super){
				pSup = pSup -> sig;
			}

			if(pSup != nullptr && pSup -> ident == super){		//Si existe super
				pSup -> numDepend = pSup -> numDepend+1;	//Sumar depend de super

				typename colecInterdep<I,V>::Celda* pAux = c.prim;
				c.prim = new typename colecInterdep<I,V>::Celda;
				c.prim -> ident = id;
				c.prim -> valor = v;
				c.prim -> dep = pSup;
				c.prim -> numDepend = 0;
				c.prim -> sig = pAux;
				c.tam++;
			}
		}

		else if(c.prim -> ident != id){		//general (entre 2 interdep o al final)
			typename colecInterdep<I,V>::Celda* pAux = c.prim;
			typename colecInterdep<I,V>::Celda* pSup = c.prim;
			while(pAux -> sig != nullptr && (pAux -> sig -> ident < id)){
				pAux = pAux -> sig;
			}
			while(pSup != nullptr && pSup -> ident < super){
				pSup = pSup -> sig;
			}
				
			if((pAux->sig == nullptr || pAux -> sig -> ident != id) && (pSup != nullptr && pSup -> ident == super)){ //Si no existe id y existe super
				typename colecInterdep<I,V>::Celda* pNuevo;
				pNuevo = new typename colecInterdep<I,V>::Celda;
				pNuevo -> ident = id;
				pNuevo -> valor = v;
				pNuevo -> dep = pSup;
				pNuevo -> numDepend = 0;
				pNuevo -> sig = pAux -> sig;
				pAux -> sig = pNuevo;
				c.tam++;		
			}
		}
	}	
}




template<typename I,typename V>
void hacerDependiente(colecInterdep<I,V>& c, const I& id, const I& super){

	if( id!=super){
		typename colecInterdep<I,V>::Celda* pSuper = c.prim;
		typename colecInterdep<I,V>::Celda* pId = c.prim;
		bool encontradoS = false;
		bool encontradoId = false;
   		while ( (!encontradoS || !encontradoId) || (pSuper != nullptr) ) {
			if(pSuper->ident == id ){
				encontradoId=true;
				typename colecInterdep<I,V>::Celda* pId = pSuper;
			}
			if(pSuper->ident == super){
				encontradoS=true;
			}else{
				pSuper = pSuper->sig;
			}
			
		}
	
		if(encontradoS && encontradoId){
				pSuper->numDepend++;
				if(pId->dep != nullptr){
					pId->dep->numDepend--;
				}
				pId->dep = pSuper;

		
			}	
	
		}

	}




template<typename I,typename V>
void hacerIndependiente(colecInterdep<I,V>& c, const I& id){
	typename colecInterdep<I,V>::Celda* pId = c.prim;
	bool encontrado = false;
   	while (pId != nullptr && pId ->ident < id ){
 		pId = pId->sig;
	}
	if(pId->ident == id){
		encontrado=true;
	} 
	if(encontrado){
		if(pId->dep!=nullptr){
			pId->dep->numDepend--;
			pId->dep=nullptr;
		}
	}
}






template<typename I,typename V>
void actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo){
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){
			pAux -> valor = nuevo;
	}
}



template<typename I,typename V>
V obtenerVal(const I& id, colecInterdep<I,V>& c){
	if(existeDependiente(id, c)||existeIndependiente(id, c)){	
		typename colecInterdep<I,V>::Celda* pAux = c.prim;
		while(pAux!=nullptr && pAux -> ident < id){
			pAux = pAux -> sig;
		}
		if(pAux!=nullptr && pAux -> ident == id){
			return pAux -> valor;
		}
	}
}



template<typename I,typename V>
I obtenerSupervisor(const I& id, colecInterdep<I,V>& c){
	if(existeDependiente(id, c)){
		typename colecInterdep<I,V>::Celda* pAux = c.prim;
		while(pAux!=nullptr && pAux -> ident < id){
			pAux = pAux -> sig;
		}
		if(pAux!=nullptr && pAux -> ident == id){
			return pAux ->dep->ident;
		}		
	}
}


template<typename I,typename V>
int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c){
	if(existe(id, c)){
		typename colecInterdep<I,V>::Celda* pAux = c.prim;
		while(pAux!=nullptr && pAux -> ident < id){
			pAux = pAux -> sig;
		}
		if(pAux!=nullptr && pAux -> ident == id){
			return pAux -> numDepend;
		}		
	}
}


template<typename I ,typename V>
void borrar(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>::Celda* pAux1;
	typename colecInterdep<I,V>::Celda* pAux2;
	bool parar;
	if(!esVacia(c)){
			if(c.prim->ident == id && c.prim->numDepend == 0){
				pAux1=c.prim;
				c.prim=c.prim->sig;
				if(pAux1->dep != nullptr){
					pAux1->dep->numDepend--;
				}
				delete pAux1;
				c.tam--;

			}else{
				parar = false;
				pAux1=c.prim->sig;
				pAux2=c.prim;
				while(pAux1 != nullptr && !parar){	
					if(id<pAux1->ident){
						parar=true;
	
					}else if( id == pAux1->ident && pAux1->numDepend == 0 ){
						if(pAux1->dep != nullptr){
							pAux1->dep->numDepend--;
						}
						pAux2->sig=pAux1->sig;
						delete pAux1;
						parar=true;
						c.tam--;
	
					}else{
						pAux2=pAux1;
						pAux1=pAux1->sig;
					}

				}

			}

	}

}



//ITERADOR
template<typename I,typename V>
void iniciarIterador(colecInterdep<I,V>& c){
	c.itr = c.prim;
}


template<typename I,typename V>
bool existeSiguiente(colecInterdep<I,V>& c){
	return c.itr != nullptr;
}



template<typename I,typename V>
I siguienteIdent(colecInterdep<I,V>& c){	//no definida si existe siguiente
	if(existeSiguiente(c)){
		return c.itr -> ident;
	}
}



template<typename I,typename V>
V siguienteVal(colecInterdep<I,V>& c){	//no definida si existe siguiente
	if(existeSiguiente(c)){
		return c.itr -> valor;
	}
}



template<typename I,typename V>
bool siguienteDependiente(colecInterdep<I,V>& c){	//no definida si existe siguiente
	if(existeSiguiente(c)){
		return c.itr -> dep != nullptr;
	}
}


template<typename I,typename V>
I siguienteSuperior(colecInterdep<I,V>& c){	//no definida si existe siguiente o es depend
	return c.itr -> dep -> ident;
}


template<typename I,typename V>
int siguienteNumDependientes(colecInterdep<I,V>& c){	//no definida si existe siguiente
	if(existeSiguiente(c)){
		return c.itr -> numDepend;
	}
}


template<typename I,typename V>
void avanza(colecInterdep<I,V>& c){	//no definida si existe siguiente
	c.itr = c.itr -> sig;
}




#endif