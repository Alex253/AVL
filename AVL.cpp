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
//Constructor Vacío
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
	private
		Nodo * raiz;
	public
		//Constructores
		AVL();
		AVL(Nodo * n);
		
		//getters
		Nodo * getRaiz(){
			return this->raiz;
		};
		//setters
		void setRaiz(Nodo * n){
			this->raiz = n;
		};
};

int main(){
	Nodo *n1 = new Nodo("Juan");
	Nodo *n2 = new Nodo("Maca");
	Nodo *n = new Nodo("Alexis",n1,n2);
	cout << "Altura Alexis: " << n->getAlturaNodo() << endl;
	cout << "Altura Maca: " << n2->getAlturaNodo() << endl;
	cout << "Altura Juan: " << n1->getAlturaNodo() << endl;
}
