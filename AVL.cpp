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
		bool balanceado(){
			if (this->hd == NULL && this->hi == NULL){
				return true;
			}else if (this->hd != NULL && this->hi != NULL){
				//si tiene ambos hijos hay que calcular la altura de ambos
				// y compararla entre ellas (solo puede ser 1 mayor para estar balanceado)
				return (1 + this->hd->getAlturaNodo() == this->hi->getAlturaNodo()
							|| this->hd->getAlturaNodo() == this->hi->getAlturaNodo() + 1);
			}else if(this->hd != NULL){
				//al no entrar en los if anteriores indica que el izquierdo es no nulo
				return this->hd->getAlturaNodo() == 1;
			}else {
				return this->hi->getAlturaNodo() == 1;
			}
		}
		
		void aumentarRepeticiones(){
			this->repeticiones += 1;
		}
		int getAlturaNodo(){
			if (this->hd != NULL && this->hi != NULL){
				int alturaDerecha = this->hd->getAlturaNodo();
				int alturaIzquierda = this->hi->getAlturaNodo();
				return 1 + (alturaDerecha >= alturaIzquierda ?
										alturaDerecha : alturaIzquierda);
			}else if(this->hd){
				return 1 + this->hd->getAlturaNodo();
			}else if(this->hi){
				return 1 + this->hi->getAlturaNodo();
			}else{
				return 1;
			}
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
		
		void insertar(string p, Nodo * origen){
			string palabraNodo = origen->getPalabra();
			if(palabraNodo == p){
				origen->aumentarRepeticiones();
				return;
			}
			if(p < palabraNodo && origen->getHI() != NULL)
				return insertar(p, origen->getHI());
			if(p < palabraNodo && origen->getHI() == NULL)
				//crear un nuevo nodo con la palabra
				origen->setHI(new Nodo(p));
			if(p > palabraNodo && origen->getHD() != NULL)
				return insertar(p, origen->getHD());
			if(p > palabraNodo && origen->getHD() == NULL)
				//crear un nuevo nodo con la palabra
				origen->setHD(new Nodo(p));
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

int main(){
	Nodo *n = new Nodo("alexis");
	
	AVL *avl = new AVL(n);
	cout << avl->search("alexis", avl->getRaiz());
	
	cout << "\n\nInsertar aa\n";
	avl->insertar("aa", avl->getRaiz());
	cout << (avl->search("aa",avl->getRaiz()) ? "OK" : "Fallo!") << endl;
	cout << "\n\nInsertar maca\n";
	avl->insertar("maca", avl->getRaiz());
	cout << (avl->search("maca",avl->getRaiz()) ? "OK" : "Fallo!") << endl;
	cout << "\n\nInsertar jose\n";
	avl->insertar("jose", avl->getRaiz());
	cout << (avl->search("jose",avl->getRaiz()) ? "OK" : "Fallo!") << endl;
	cout << "\n\nInsertar berni\n";
	//avl->insertar("berni", avl->getRaiz());
	cout << (avl->search("berni",avl->getRaiz()) ? "OK" : "Fallo!") << endl;
	
	cout << "_________________\n";
	cout << "Altura Arbol: " << avl->getRaiz()->getAlturaNodo() << endl;
	cout << endl << avl->getRaiz()->balanceado();
}
