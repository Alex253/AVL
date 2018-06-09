#include <iostream>

using namespace std;
class Nodo{
	private:
		int repeticiones;
		string palabra;
		Nodo *hd;
		Nodo *hi;
		
	public:
		//Constructores
		Nodo();
		Nodo(string p);
		Nodo(string p, Nodo * hijoi, Nodo *hijod);
		
		//Metodos generales
		void aumentarRepeticiones(){
			this->repeticiones += 1;
		}
		int getAlturaNodo(){
			//Si ambos hijos no fueron seteados devuelve 1
			if(this->hd == NULL && this->hi == NULL)
				return 1;
			//Si ambos fueron seteados devuelve el mayor
			if(this->hd != NULL && this->hi != NULL)
				return (this->hd->getAlturaNodo() > this->hi->getAlturaNodo()) ?
						1 + this->hd->getAlturaNodo() :
						1 + this->hi->getAlturaNodo();
			//Si el derecho es nulo y el izquierdo no devuelve la altura izq
			if(this->hd == NULL && this->hi != NULL)
				return 1 + this->hi->getAlturaNodo();
			//Si el izquierdo es nulo y el derecho no, devuelve la altura derecha
			if(this->hd != NULL && this->hi == NULL)
				return 1 + this->hi->getAlturaNodo();
		}
		//seters
		void setHD(Nodo * h){
			this->hd = h;
		};
		void setHI(Nodo * h){
			this->hi = h;
		};
		void setPalabra(string p){
			this->palabra = p;
		};
		void setRepeticiones(int r){
			this->repeticiones = r;
		};
		
		//getters
		Nodo * getHI(){
			return this->hi;
		};
		Nodo * getHD(){
			return this->hd;
		};
		string getPalabra(){
			return this->palabra;
		};
		int getRepeticiones(){
			return this->repeticiones;
		};
};
//Constructor Vac�o
Nodo::Nodo(){
	this->hd = NULL;
	this->hi = NULL;
}
//Constructor de Nodo Con Palabra
Nodo::Nodo(string p){
	this->hd = NULL;
	this->hi = NULL;
	this->palabra = p;
	this->repeticiones = 1;
}
Nodo::Nodo(string p, Nodo * hijoi, Nodo * hijod){
	this->hi = hijoi;
	this->hd = hijod;
	this->palabra = p;
	this->repeticiones = 1;
}

class AVL{
	private:
		Nodo * raiz;
	public:
		//Constructores
		AVL();
		AVL(Nodo * n);
		
		//metodos generales
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

int main(){
	Nodo *n1 = new Nodo("Juan");
	Nodo *n2 = new Nodo("Maca");
	Nodo *n = new Nodo("Alexis");
	/*
	cout << "Altura Alexis: " << n->getAlturaNodo() << endl;
	cout << "Altura Maca: " << n2->getAlturaNodo() << endl;
	cout << "Altura Juan: " << n1->getAlturaNodo() << endl;
	*/
	AVL *avl = new AVL(n);
	cout << avl->search("Alexis", avl->getRaiz());
	cout << avl->search("alexis", avl->getRaiz());
}
