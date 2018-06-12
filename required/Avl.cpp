class AVL{
	private:
		Nodo * raiz;
	public:
		//Constructores
		AVL();
		AVL(Nodo * n);
		AVL(string palabra);
		//metodos generales
		void toPrint(Nodo *n){
			//IMPRIME IZQUIERDA, NODO, DERECHA (ORDEN ALFABETICO)
			if(n != NULL){
				toPrint(n->getHI());
				cout << "\n" << n->getPalabra() << endl;
				toPrint(n->getHD());
			}
			return;
		}
		int getAltura(){
			return this->raiz->getAlturaNodo();
		}
		
		bool search(string p, Nodo * origen){
			string palabraNodo = origen->getPalabra();
			if(palabraNodo == p){
				return true;
			}
			if(p < palabraNodo && origen->getHI() != NULL)
				return search(p, origen->getHI());
			if(p < palabraNodo && origen->getHI() == NULL)
				return false;
			if(p > palabraNodo && origen->getHD() != NULL)
				return search(p, origen->getHD());
			if(p > palabraNodo && origen->getHD() == NULL)
				return false;
			return false;
		}
		
		void balancear(Nodo * nod){
			if(nod != NULL){
				//cout << "intentando balancear:" << nod->getPalabra() << endl << endl;
				this->balancear(nod->getHI());
				this->balancear(nod->getHD());
				nod->balancear();
			}
			return;
		}
		
		void insertar(string p, Nodo * origen){
			string palabraNodo = origen->getPalabra();
			if(palabraNodo == p){
				origen->aumentarRepeticiones();
				return;
			}else	if(p < palabraNodo && origen->getHI() != NULL){
				return insertar(p, origen->getHI());
			}else	if(p < palabraNodo && origen->getHI() == NULL){
				//crear un nuevo nodo con la palabra
				origen->setHI(new Nodo(p));
			}else if(p > palabraNodo && origen->getHD() != NULL){
				return insertar(p, origen->getHD());
			}else if(p > palabraNodo && origen->getHD() == NULL){
				//crear un nuevo nodo con la palabra
				origen->setHD(new Nodo(p));
			}
			this->balancear(this->raiz);
			return;
		}
		
		//getters
		Nodo * getRaiz(){
			return this->raiz;
		};
		//setters
		void setRaiz(Nodo * n){
			this->raiz = n;
		};
};

AVL::AVL(){
	this->raiz = NULL;
}

AVL::AVL(Nodo * n){
	this->raiz = n;
}
AVL::AVL(string cadena){
	this->raiz = new Nodo(cadena);
}


