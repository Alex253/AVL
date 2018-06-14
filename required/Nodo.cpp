#include <iostream>
#include <string>
using namespace std;
class Nodo{
	private:
		int repeticiones;
		string palabra;
		Nodo *hd;
		Nodo *hi;
		void caso1();
		void caso2();
		void caso3();
		void caso4();
		
	public:
		//Constructores
		Nodo();
		Nodo(string p);
		Nodo(string p, Nodo * hijoi, Nodo *hijod);
		
		//Metodos generales
		bool balanceado();
		Nodo * clone();
		void balancear();
		void aumentarRepeticiones();
		int getAlturaNodo();
		
		//seters
		void setHD(Nodo * h);
		void setHI(Nodo * h);
		void setPalabra(string p);
		void setRepeticiones(int r);
		
		//getters
		Nodo * getHI();
		Nodo * getHD();
		string getPalabra();
		int getRepeticiones();
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

/**
 *
 * Rama Izquierda -> Derecha desbalanceada
 * K1 es el Nodo padre
 * X es el nodo hijo izquierdo
 * K2 es el nodo hijo derecho (que representa el desbalanceo)
 * Y es el nodo hijo izquierdo de K2
 * Z es el nodo hijo drecho de K2
 *
 */
void Nodo::caso1(){
	Nodo *k1 = this;
	Nodo *k2 = this->getHI();
	if (k1 != NULL && k2 != NULL){
		Nodo *x = k2->getHI();
		Nodo *y = k2->getHD();
		Nodo *z = k1->getHD();
		Nodo * aux;
		if(x != NULL && y != NULL && z != NULL){
			if(z->getAlturaNodo() < k2->getAlturaNodo() - 1 && x->getAlturaNodo() > y->getAlturaNodo()){
				//DO ROTATE
				cout << "se ha generado el caso 1\n\n";
				aux = k2->clone();
				aux->setHD(k1->clone());
				aux->getHD()->setHI(y);
				this->setHD(aux->getHD());
				this->setHI(aux->getHI());
				this->setPalabra(aux->getPalabra());
				this->setRepeticiones(aux->getRepeticiones());
			}
		}
	}
}

void Nodo::caso2(){
	Nodo * k1 = this;
	Nodo * k2 = this->getHD();
	if (k1 != NULL && k2 != NULL){
		Nodo * x = k2->getHD();
		Nodo * y = k2->getHI();
		Nodo * z = k1->getHI();
		Nodo * aux;
		if(x != NULL && y != NULL && z != NULL){
			if(z->getAlturaNodo() < k2->getAlturaNodo() - 1 && x->getAlturaNodo() > y->getAlturaNodo()){
				//DO ROTATE
				cout << "se ha generado el caso 2\n\n";
				aux = k2->clone();
				aux->setHI(k1->clone());
				aux->getHI()->setHD(y);
				this->setHD(aux->getHD());
				this->setHI(aux->getHI());
				this->setPalabra(aux->getPalabra());
				this->setRepeticiones(aux->getRepeticiones());
			}
		}
	}
}

void Nodo::caso3(){
	Nodo * aux;
	Nodo * k1 = this;
	Nodo * k2 = this->getHI();
	if (k1 != NULL && k2 != NULL){
		Nodo * z = k1->getHD();
		Nodo * k3 = k2->getHD();
		Nodo * x = k2->getHI();
		if (k3 != NULL && z != NULL && x != NULL){
			Nodo * y1 = k3->getHI();
			Nodo * y2 = k3->getHD();
			if(y1 != NULL && y2 != NULL){
				if(k2->getAlturaNodo() - 1 > z->getAlturaNodo() && k3->getAlturaNodo() > x->getAlturaNodo()){
					//DO ROTATE
					cout << "se ha generado el caso 3\n\n";
					aux = k3->clone();
					aux->setHI(k2->clone());
					aux->setHD(k1->clone());
					aux->getHI()->setHD(y1->clone());
					aux->getHD()->setHI(y2->clone());
					this->setHD(aux->getHD());
					this->setHI(aux->getHI());
					this->setPalabra(aux->getPalabra());
					this->setRepeticiones(aux->getRepeticiones());
				}
			}
		}	
	}
}

void Nodo::caso4(){
	Nodo * aux;
	Nodo * k1 = this;
	Nodo * z = this->getHI();
	Nodo * k2 = this->getHD();
	if (k1 != NULL && k2 != NULL && z != NULL){
		Nodo * k3 = k2->getHI();
		Nodo * x = k2->getHD();
		if (k3 != NULL && x != NULL){
			Nodo * y1 = k3->getHI();
			Nodo * y2 = k3->getHD();
			if(y1 != NULL && y2 != NULL){
				if(k2->getAlturaNodo() - 1 > z->getAlturaNodo() && k3->getAlturaNodo() > x->getAlturaNodo()){
					//DO ROTATE
					cout << "Se ha generado el caso 4\n\n";
					aux = k3->clone();
					aux->setHI(k1->clone());
					aux->getHI()->setHD(y1);
					aux->setHD(k2->clone());
					aux->getHD()->setHI(y2);
					this->setHI(aux->getHI());
					this->setHD(aux->getHD());
					this->setPalabra(aux->getPalabra());
					this->setRepeticiones(aux->getRepeticiones());
				}
			}
		}
	}
}

bool Nodo::balanceado(){
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

Nodo * Nodo::clone(){
	Nodo * clon = new Nodo(this->palabra, this->hi, this->hd);
	clon->setRepeticiones(this->repeticiones);
	return clon;
}

void Nodo::balancear(){
	this->caso1();
	this->caso2();
	this->caso3();
	this->caso4();
}

void Nodo::aumentarRepeticiones(){
	this->repeticiones += 1;
}

int Nodo::getAlturaNodo(){
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

//SETTERS
void Nodo::setHD(Nodo * h){
	this->hd = h;
}

void Nodo::setHI(Nodo * h){
	this->hi = h;
}

void Nodo::setPalabra(string p){
	this->palabra = p;
}

void Nodo::setRepeticiones(int r){
	this->repeticiones = r;
}

//GETTERS
Nodo * Nodo::getHD(){
	return this->hd;
}

Nodo * Nodo::getHI(){
	return this->hi;
}

string Nodo::getPalabra(){
	return this->palabra;
}

int Nodo::getRepeticiones(){
	return this->repeticiones;
}

