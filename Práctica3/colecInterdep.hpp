// Mijayl Mandzyak Melnyk 935521 Hector Manzano Miranda 926029 
#ifndef COLECINTEDEP_HPP
#define COLECINTEDEP_HPP

// PREDECLARACION DEL TAD GENERICO colecInterdep (inicio INTERFAZ)

/*El TAD GENERICO  colecInterdep es una colección ordenada de elementos cuyo dominio de valores seran de datos
 * booleanos(bool) y datos naturales(int).
 *
 * Todas las funciones de la colcección tienen coste lineal O(n) salvo crear, tamanyo y esVacia que tienen coste
 * constante. Todas las funciones del iterador tienen coste constante.
 * Igualmente, el coste en memoria de esta implementación será O(N).
 * 
 * Al parámetro formal I le exigimos estar dotado de los operadores habituales de: 
 * comparación de igualdad == , y anterior <
 * bool operator==(const I& i1, const I& i2); 
 * bool operator<(const I& i1, const I& i2);
 *
 */ 
template<typename I,typename V> struct colecInterdep;




/* Crea una colección c vacía, sin elementos.
*/
template<typename I,typename V> void crear(colecInterdep<I,V>& c);


/* Dada una colección "c", devuelve el número de elementos que hay en esta en forma de entero.
*/
template<typename I,typename V> int tamanyo(colecInterdep<I,V>& c);


/* Dada una colección "c", devuelve en forma de booleano si esta es vacía, es decir, no tiene ningún elemento.
 * Devuelve TRUE si y solo si esta es vacía y false si no lo es.
*/
template<typename I,typename V> bool esVacia(colecInterdep<I,V>& c);


/* Dado un identificador "id" y una colección "c", devuelve en forma de booleano TRUE si y solo si en c hay un
 * elemento con el identificador aportado. Devuelve FALSE en caso contrario.
*/
template<typename I,typename V> bool existe(const I& id, colecInterdep<I,V>& c);


/* Dado un identificador "id" y una colección "c", devuelve en forma de booleano TRUE si y solo si en c hay un
 * elemento con el identificador aportado y que sea dependiente de otro elemento. Devuelve FALSE en caso de no
 * encontrar dicho elemento o que este no sea dependiente.
*/
template<typename I,typename V> bool existeDependiente(const I& id, colecInterdep<I,V>& c);


/* Dado un identificador "id" y una colección "c", devuelve en forma de booleano TRUE si y solo si en c hay un
 * elemento con el identificador aportado y que no sea dependiente de otro elemento. Devuelve FALSE en caso de
 * no encontrar dicho elemento o que este sea dependiente.
*/
template<typename I,typename V> bool existeIndependiente(const I& id, colecInterdep<I,V>& c);


/* Dada una colección "c", un identificador "id" y un valor "v", si no se encuentra un elemento con el identificador
 * aportado en la colección devuelve el resultante de añadir el elemento independiente (id,v,-,0) a la colección 
 * c con dicho identificador y valor. En caso de que exista un elemento con tal identificador devuelve una igual
 * a c sin modificar.
*/
template<typename I,typename V> void anyadirIndependiente(colecInterdep<I,V>& c, const I& id, const V& v);


/* Dada una colección "c", un identificador "id", un valor "v" y un identificador "super", si no se encuentra un 
 * elemento con el identificador id aportado en la colección y existe un elemento con identificador super devuelve 
 * el resultante de añadir el elemento dependiente (id,v,super,0) a la colección c e incrementar en 1 el número 
 * de elementos dependientes del elemento con identificador super. En caso de que exista un elemento con tal identificador
 * o no exista un elemento con identificador super devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V> void anyadirDependiente(colecInterdep<I,V>& c, const I& id, const V& v, const I& super);


/* Dada una colección "c", un identificador "id" y un identificador "super", si existe un elemento con el identificador
 * id en la colección y existe un elemento con identificador super incrementa en 1 el el número de elementos dependientes 
 * del elemento con identificador super y hace dependiente al elemento con identificador id del de super. En caso 
 * de que el elemento con identificador id dependiese de otro elemento previamente, decrementa en 1 el numero de 
 * elementos dependientes de dicho elemento del que dependia.
 * Si no existe un elemento con el identificador id en la colección o no existe un elemento con identificador super 
 * devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V> void hacerDependiente(colecInterdep<I,V>& c, const I& id, const I& super);


/* Dada una colección "c" y un identificador "id", si existe un elemento con el identificador id en la colección 
 * y este es dependiente de otro elemento decrementa en 1 el número de elementos dependientes del elemento del
 * que dependía y hacer independiente el elemento con identificador id.
 * Si no existe un elemento con el identificador id en la colección o este ya era un elemento con independiente
 * super devuelve una colección igual a c sin modificar.
*/
template<typename I,typename V> void hacerIndependiente(colecInterdep<I,V>& c, const I& id);


/* Dada una colección "c", un identificador "id" y un valor "nuevo", si existe un elemento con el identificador id 
 * en la colección actualiza su valor por el valor nuevo y devuelve en forma de booleano TRUE si y solo si se ha 
 * actualizado correctamente. Devuelve FALSE si no se ha podido actualizar por la inexistencia del elemento.
*/
template<typename I,typename V> bool actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo);


/* Dado un identificador "id", una colección "c" y un valor "val", si existe un elemento con el identificador id 
 * en la colección le proporciona a val el valor del elemento y devuelve en forma de booleano TRUE si y solo si 
 * el valor val se ha actualizado correctamente. Devuelve FALSE si no se ha podido actualizar por la inexistencia
 * del elemento.
*/
template<typename I,typename V> bool obtenerVal(const I& id, colecInterdep<I,V>& c, V& val);


/* Dado un identificador "id", una colección "c" y un identificador "sup", si existe un elemento con el identificador
 * id en la colección le proporciona a sup el identificador del elemento del que depende el elemento con identidicador
 * id y devuelve en forma de booleano TRUE si y solo si el identificador sup se ha actualizado correctamente. Devuelve
 * FALSE si no se ha podido actualizar por la inexistencia
 * del elemento.
*/
template<typename I,typename V> bool obtenerSupervisor(const I& id, colecInterdep<I,V>& c, I& sup);


/* Dado un identificador "id" y una colección "c", si existe un elemento con el identificador id devuelve en forma
 * de entero el numero de elementos que dependen del elemento. Devuelve -1 si existe tal elemento en la coleccion c.
*/
template<typename I,typename V> int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c);


/* Dado un identificador "id" y una colección "c", si existe un elemento con el identificador id y este es independiente
 * devuelve la colección c resultante de eliminar el elemento de la colección c. Si este elemento es dependiente
 * además decrementa en 1 el numero de elementos dependientes del que este dependía.
 * Si el elemento no existe devuelve la misma colección c sin modificar.
*/
template<typename I,typename V> void borrar(const I& id, colecInterdep<I,V>& c);



/* Devuelve true si y sólo si id1 y id2 tienen el mismo identificador. 
 * Cada elemento de la colección puede ser comparado utilizando el operador == de los datos de tipo I.
*/
template<typename I> bool operator==(const I& id1, const I& id2);


/* Devuelve true si y sólo si id1 tiene un identificador mayor/posterior a id2. 
 * Cada elemento de la colección puede ser comparado utilizando el operador < de los datos de tipo I.
*/
template<typename I> bool operator>(const I& id1, const I& id2);



/* Dada una colección c, inicia el iterador para que el siguiente elemento a visitar sea el primer elemento de c
 * si existe
*/
template<typename I,typename V> void iniciarIterador(colecInterdep<I,V>& c);


/* Dada una colección c, devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la
 * colección y FALSE en caso contrario.
*/
template<typename I,typename V> bool existeSiguiente(colecInterdep<I,V>& c);


/* Dada una colección c y un identificador id, si queda algún elemento por visitar en la colección modifica id
 * con el identificador del elemento visitado y devuelve TRUE en forma de booleano. En caso contrario devuelve
 * FALSE. 
*/
template<typename I,typename V> bool siguienteIdent(colecInterdep<I,V>& c, I& id);


/* Dada una colección c y un valor sup, si queda algún elemento por visitar en la colección c modifica val con
 * el valor del elemento visitado y devuelve TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V> bool siguienteVal(colecInterdep<I,V>& c, V& val);


/* Dada una colección c, devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la
 * colección c y dicho elemento es dependiente de otro. Devuelve FALSE si no se cumplen ambas condiciones.
*/
template<typename I,typename V> bool siguienteDependiente(colecInterdep<I,V>& c);


/* Dada una colección c y un valor sup, si queda algún elemento dependiente por visitar en la colección c modifica 
 * sup con el identificador del elemento visitado y devuelve TRUE en forma de booleano. En caso de que no queden
 * elemetos por visitar o que este sea independiente devuelve FALSE. 
*/
template<typename I,typename V> bool siguienteSuperior(colecInterdep<I,V>& c, I& sup);


/* Dada una colección c,  si queda algún elemento por visitar en la colección c devuelve el numero de elementos
 * dependientes del elemento visitado. Devuelve -1 si no se quedan elementos por visitar.
*/
template<typename I,typename V> int siguienteNumDependientes(colecInterdep<I,V>& c);


/* Dada una colección c, devuelve en forma de booleano TRUE si existen elementos por visitar y hace que el iterador 
 * avance para visitar el siguiente elemento de la colección. Devuelve FALSE en caso contrario y no avanza.
*/
template<typename I,typename V> bool avanza(colecInterdep<I,V>& c);



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
	friend bool actualizarVal<I,V>(colecInterdep<I,V>& c, const I& id, const V& v);
	friend bool obtenerVal<I,V>(const I& id, colecInterdep<I,V>& c, V& val);
	friend bool obtenerSupervisor<I,V>(const I& id, colecInterdep<I,V>& c, I& sup);
	friend int obtenerNumDependientes<I,V>(const I& id, colecInterdep<I,V>& c);
	friend void borrar<I,V>(const I& id, colecInterdep<I,V>& c);
	
	friend bool operator==<I>(const I& id1, const I& id2);
	friend bool operator><I>(const I& id1, const I& id2);

	friend void iniciarIterador<I,V>(colecInterdep<I,V>& c);
	friend bool existeSiguiente<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteIdent<I,V>(colecInterdep<I,V>& c, I& id);
	friend bool siguienteVal<I,V>(colecInterdep<I,V>& c, V& val);
	friend bool siguienteDependiente<I,V>(colecInterdep<I,V>& c);
	friend bool siguienteSuperior<I,V>(colecInterdep<I,V>& c, I& sup);
	friend int siguienteNumDependientes<I,V>(colecInterdep<I,V>& c);
	friend bool avanza<I,V>(colecInterdep<I,V>& c);

    

  private: /* En esta implementación la colección se representará en memoria dinámica como una lista enlazada de Celdas ordenada 
  			* por el identificdor de los elementos de menor a mayor con: 
	        * - el puntero prim: apuntando a la Celda que contiene el primer elemento de la colección, será nullptr si la colección
			* está vacía
		    * - el campo tam: mantendrá calculado el tamaño o número de elementos en la colección, será 0 si la pila está vacía 
		    * - el puntero itr: se utilizará para mantener el estado del iterador, y únicamente será utilizado por las operaciones 
			* iniciarIterador, existeSiguiente, siguienteIdent, siguienteVal, siguienteDependiente, siguienteSuperior, siguienteNumDependientes
			* y avanza.
			* Cada Celda contendrá un identificador (en su campo ident), un valor (en su campo valor), apuntará con su puntero dep 
			* al elemento del que es dependiente o a nullptr si es independiente, un entero que almacenará el número de elementos 
			* que dependen de este y apuntará con su puntero sig a la próxima Celda que contenga el primer elemento con un identificador
			* mayor a este o a nullptr si este es el elemento con mayor identificador.
	   
    Todas las funciones de la colcección tienen coste lineal O(n) salvo crear, tamanyo y esVacia que tienen coste
	constante. Todas las funciones del iterador tienen coste constante.
	Igualmente, el coste en memoria de esta implementación será O(N).
	*/
	struct Celda{
	I ident;
	V valor;
	Celda* dep;
	int numDepend;
	Celda* sig;
};


	Celda* prim;
	int tam;
    //CAMPOS ITERADOR
	Celda* itr;
};
	


//OPERACIONES

/* Crea una colección c vacía, sin elementos.
*/
template<typename I,typename V> 
void crear(colecInterdep<I,V>& c){
	c.tam=0;
	c.prim=nullptr;
	c.itr=nullptr;

}


/* Dada una colección "c", devuelve el número de elementos que hay en esta en forma de entero.
*/
template<typename I,typename V>
int tamanyo(colecInterdep<I,V>& c){
	return c.tam;

}


/* Dada una colección "c", devuelve en forma de booleano si esta es vacía, es decir, no tiene ningún elemento.
 * Devuelve TRUE si y solo si esta es vacía y false si no lo es.
*/
template<typename I,typename V>
bool esVacia(colecInterdep<I,V>& c){
	return c.prim == nullptr;
}


/* Dado un identificador "id" y una colección "c", devuelve en forma de booleano TRUE si y solo si en c hay un
 * elemento con el identificador aportado. Devuelve FALSE en caso contrario.
*/
template<typename I,typename V> 
bool existe(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>::Celda* pAux = c.prim;

    // Recorremos mientras no se acabe la colección y la clave actual sea menor que la buscada
    while (pAux != nullptr && pAux->ident < id) {
        pAux = pAux->sig;
    }

    if (pAux == nullptr) {
      	return false;
    } 
	else{
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
			typename colecInterdep<I,V>::Celda* pSup = nullptr;
			typename colecInterdep<I,V>::Celda* pId = nullptr;
			bool encontradoS = false;
			bool idNuevo = true;
			bool pararId = false;
			while ( (!encontradoS || !pararId) && (pAux != nullptr) ) {
				if(pAux->ident < id){
					pId = pAux;
				}
				else if(pAux->ident == id){
					idNuevo = false;
					pararId = true;
				}
				else if(pAux->ident > id){
					pararId = true;
				}
				if(pAux->ident == super){
					encontradoS=true;
					pSup = pAux;
				}

				pAux = pAux->sig;
			
			}
				
			if(idNuevo && encontradoS){ //Si no existe id y existe super
				pSup -> numDepend = pSup -> numDepend+1;
				
				typename colecInterdep<I,V>::Celda* pNuevo;
				pNuevo = new typename colecInterdep<I,V>::Celda;
				pNuevo -> ident = id;
				pNuevo -> valor = v;
				pNuevo -> dep = pSup;
				pNuevo -> numDepend = 0;
				pNuevo -> sig = pId -> sig;
				pId -> sig = pNuevo;
				c.tam++;		
			}
		}
	}	
}




template<typename I,typename V>
void hacerDependiente(colecInterdep<I,V>& c, const I& id, const I& super){

	if( id!=super){
		typename colecInterdep<I,V>::Celda* pAux = c.prim;
		typename colecInterdep<I,V>::Celda* pSuper = nullptr;
		typename colecInterdep<I,V>::Celda* pId = nullptr;
		bool encontradoS = false;
		bool encontradoId = false;
   		while ( (!encontradoS || !encontradoId) || (pAux != nullptr) ) {
			if(pAux->ident == id ){
				encontradoId=true;
				pId = pAux;
			}
			else if(pAux->ident == super){
				encontradoS=true;
				pSuper = pAux;
			}
			pAux = pAux->sig;
			
			
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
   	while (pId != nullptr && pId ->ident < id ){
 		pId = pId->sig;
	}
	if(pId != nullptr && pId->ident == id){
		if(pId->dep!=nullptr){
			pId->dep->numDepend--;
			pId->dep=nullptr;
		}
	}
}






template<typename I,typename V>
bool actualizarVal(colecInterdep<I,V>& c, const I& id, const V& nuevo){
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){
			pAux -> valor = nuevo;
			return true;
	}
	else{
		return false;
	}
}



template<typename I,typename V>
bool obtenerVal(const I& id, colecInterdep<I,V>& c, V& val){	//existeDependiente(id, c)||existeIndependiente(id, c)
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){
		val = pAux -> valor;
		return true;
	}
	else{
		return false;
	}
}



template<typename I,typename V>
bool obtenerSupervisor(const I& id, colecInterdep<I,V>& c, I& sup){
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){
		sup = pAux ->dep->ident;
		return true;
	}
	else{
		return false;
	}
}


template<typename I,typename V>
int obtenerNumDependientes(const I& id, colecInterdep<I,V>& c){
	typename colecInterdep<I,V>::Celda* pAux = c.prim;
	while(pAux!=nullptr && pAux -> ident < id){
		pAux = pAux -> sig;
	}
	if(pAux!=nullptr && pAux -> ident == id){
		return pAux -> numDepend;
	}
	else{
		return -1;
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



/* Devuelve true si y sólo si id1 y id2 tienen el mismo identificador. 
 * Cada elemento de la colección puede ser comparado utilizando el operador == de los datos de tipo I.
*/
template<typename I> bool operator==(const I& id1, const I& id2){
	return id1 == id2;
}


/* Devuelve true si y sólo si id1 tiene un identificador mayor/posterior a id2. 
 * Cada elemento de la colección puede ser comparado utilizando el operador < de los datos de tipo I.
*/
template<typename I> bool operator>(const I& id1, const I& id2){
	return id1 > id2;
}



//ITERADOR
/* Las ocho operaciones siguientes conforman un iterador interno para la colección: 
 * Este iterador permitirá visitar los elementos almacenados en la colección empezando por el primer elemento (el
 * de menor identificador) y acabando con el último elemento (el de mayor identificador).
 * Si el puntero itr de la colección tiene valor nullptr entonces no existe elemento pendiente por visitar (ya se 
 * han visitado todos los elementos), en caso contrario el puntero apunta a la Celda cuyo dato es el siguiente 
 * elemento a visitar.
*/


/* Dada una colección c, inicia el iterador para que el siguiente elemento a visitar sea el primer elemento de c
 * si existe
*/
template<typename I,typename V>
void iniciarIterador(colecInterdep<I,V>& c){
	c.itr = c.prim;
}

/* Dada una colección c, devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la
 * colección y FALSE en caso contrario.
*/
template<typename I,typename V>
bool existeSiguiente(colecInterdep<I,V>& c){
	return c.itr != nullptr;
}


/* Dada una colección c y un identificador id, si queda algún elemento por visitar en la colección modifica id
 * con el identificador del elemento visitado y devuelve TRUE en forma de booleano. En caso contrario devuelve
 * FALSE. 
*/
template<typename I,typename V>
bool siguienteIdent(colecInterdep<I,V>& c, I& id){
	if(existeSiguiente(c)){
		id = c.itr -> ident;
		return true;
	}
	else{
		return false;
	}	
}


/* Dada una colección c y un valor sup, si queda algún elemento por visitar en la colección c modifica val con
 * el valor del elemento visitado y devuelve TRUE en forma de booleano. En caso contrario devuelve FALSE. 
*/
template<typename I,typename V>
bool siguienteVal(colecInterdep<I,V>& c, V& val){
	if(existeSiguiente(c)){
		val = c.itr -> valor;
		return true;
	}
	else{
		return false;
	} 
}


/* Dada una colección c, devuelve en forma de booleano TRUE si y solo si queda algún elemento por visitar en la
 * colección c y dicho elemento es dependiente de otro. Devuelve FALSE si no se cumplen ambas condiciones.
*/
template<typename I,typename V>
bool siguienteDependiente(colecInterdep<I,V>& c){
	if(existeSiguiente(c)){
		return c.itr -> dep != nullptr;
	}
	else{
		return false;
	}
}


/* Dada una colección c y un valor sup, si queda algún elemento dependiente por visitar en la colección c modifica 
 * sup con el identificador del elemento visitado y devuelve TRUE en forma de booleano. En caso de que no queden
 * elemetos por visitar o que este sea independiente devuelve FALSE. 
*/
template<typename I,typename V>
bool siguienteSuperior(colecInterdep<I,V>& c, I& sup){
	if(siguienteDependiente(c)){
		sup = c.itr -> dep -> ident;
		return true;
	} 
	else{
		return false;
	}
}


/* Dada una colección c,  si queda algún elemento por visitar en la colección c devuelve el numero de elementos
 * dependientes del elemento visitado. Devuelve -1 si no se quedan elementos por visitar.
*/
template<typename I,typename V>
int siguienteNumDependientes(colecInterdep<I,V>& c){
	if(existeSiguiente(c)){
		return c.itr -> numDepend;
	}
	else{
		return -1;
	}
}


/* Dada una colección c, devuelve en forma de booleano TRUE si existen elementos por visitar y hace que el iterador 
 * avance para visitar el siguiente elemento de la colección, haciendo que el puntero itr pase a apuntar a su sig. 
 * Devuelve FALSE en caso contrario y no avanza.
*/
template<typename I,typename V>
bool avanza(colecInterdep<I,V>& c){
	if(existeSiguiente(c)){
		c.itr = c.itr -> sig;
		return true;
	}
	else{
		return false;
	}
}




#endif