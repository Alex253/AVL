#include "Nodo.cpp"
using namespace std;
class AVL{
	private:
		Nodo * raiz;
		
	public:
		//Constructores
		AVL();
		AVL(Nodo * n);
		AVL(string palabra);
		
		//metodos generales
		void toPrint(Nodo *n);
		bool search(string p, Nodo * origen);
		void balancear(Nodo * nod);
		void insertar(string p, Nodo * origen);
		
		//getters
		Nodo * getRaiz();
		int getAltura();
		
		//setters
		void setRaiz(Nodo * n);
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

void AVL::toPrint(Nodo * n){
	//IMPRIME IZQUIERDA, NODO, DERECHA (ORDEN ALFABETICO)
	if(n != NULL){
		toPrint(n->getHI());
		cout << "\n" << n->getPalabra() << "(" <<n->getRepeticiones() << ")" << endl;
		toPrint(n->getHD());
	}
	return;
}

bool AVL::search(string p, Nodo * origen){
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

void AVL::balancear(Nodo * nod){
	if(nod != NULL){
		this->balancear(nod->getHI());
		this->balancear(nod->getHD());
		nod->balancear();
	}
	return;
}

void AVL::insertar(string p, Nodo * origen){
	if(p == "") return;
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

//GETTERS
Nodo * AVL::getRaiz(){
	return this->raiz;
}

int AVL::getAltura(){
	return this->raiz->getAlturaNodo();
}

//SETTERS
void AVL::setRaiz(Nodo * n){
	this->raiz = n;
}
