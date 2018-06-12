#include <iostream>
#include <fstream>

using namespace std;

class Nodo{
	private:
		int repeticiones;
		string palabra;
		Nodo *hd;
		Nodo *hi;
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
		void caso1(){
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
		
		void caso2(){
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
		
		Nodo * clone(){
			Nodo * clon = new Nodo(this->palabra, this->hi, this->hd);
			clon->setRepeticiones(this->repeticiones);
			return clon;
		}
		
		void balancear(){
			cout << "llamando al caso 1" << endl;
			this->caso1();
			cout << "llamando al caso 2" << endl;
			this->caso2();
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

/* --- PROTOTYPE FUNCTIONS --- */
void leerArchivo(AVL *avl);
void caso1test();
void caso2test();

int main(){
	AVL * avl = new AVL();
	leerArchivo(avl); //datos.md
	avl->toPrint(avl->getRaiz());
	cout << "\t\t----------------------\n";
	cout << "Raiz (Berni): " << avl->getRaiz()->getPalabra() << endl;
	cout << "HI (Alexis): " << avl->getRaiz()->getHI()->getPalabra() << endl;
	cout << "HD (Camila): " << avl->getRaiz()->getHD()->getPalabra() << endl;
	cout << "Camila->HI (Botero): " << avl->getRaiz()->getHD()->getHI()->getPalabra() << endl;
	cout << "Camila->HD (Fede): " << avl->getRaiz()->getHD()->getHD()->getPalabra() << endl;
	cout << "Alexis->HI (Alejo): " << avl->getRaiz()->getHI()->getHI()->getPalabra() << endl;
	/*
	caso1test();
	caso2test();
	*/
}

void leerArchivo(AVL * avl){
	string cadena;
	ifstream lector;
	lector.open("caso1.md");
	if(lector.fail()){
		cout << "\t\t***\tERROR AL LEER EL ARCHIVO\t***\t\t\n\n";
		cout << "(Revise que el archivo 'datos.md' existe en el directorio local)\n_";
		cin.ignore(1);
	}else{
		while(lector.good()){
			lector >> cadena;
			//añadir las palabras al arbol.
			// dos posibles soluciones:
			// crear el avl como global, mandarlo desde el main como un parametro a la funcion.
			cout << "\t\t** LEYENDO PALABRA: ";
			if (avl->getRaiz() == NULL){
				cout << cadena << endl;
				cout << "raiz nula\n";
				avl->setRaiz(new Nodo(cadena));
				cout << avl->getRaiz()->getPalabra() << endl;
			}else{
				cout << cadena << endl;
				cout << "insertando : " << cadena << endl;
				avl->insertar(cadena,avl->getRaiz());
			}
			cadena.clear();
		}
		lector.close();
	}
}

void caso1test(){
	Nodo *n = new Nodo("camila");
	AVL *avl = new AVL(n);
	cout << avl->search("camila", avl->getRaiz());
	cout << "Camila(2): " << avl->getRaiz()->getRepeticiones() << "Apariciones." << endl;
	avl->insertar("berni",avl->getRaiz());
	avl->insertar("alexis",avl->getRaiz());
	avl->insertar("botero",avl->getRaiz());
	avl->insertar("alejo",avl->getRaiz());
	avl->insertar("fede",avl->getRaiz());
	avl->insertar("camila",avl->getRaiz());
	avl->insertar("camila",avl->getRaiz());
	cout << "Camila(2): " << avl->getRaiz()->getRepeticiones() << "Apariciones." << endl;
	cout << "Raiz (Camila): " << avl->getRaiz()->getPalabra() << endl;
	cout << "HI (Berni): " << avl->getRaiz()->getHI()->getPalabra() << endl;
	cout << "HD (Fede): " << avl->getRaiz()->getHD()->getPalabra() << endl;
	cout << "Berni->HI (Alexis): " << avl->getRaiz()->getHI()->getHI()->getPalabra() << endl;
	cout << "Berni->HD (Botero): " << avl->getRaiz()->getHI()->getHD()->getPalabra() << endl;
	cout << "Alexis->HI (Alejo): " << avl->getRaiz()->getHI()->getHI()->getHI()->getPalabra() << endl;
	avl->getRaiz()->balancear();
	cout << "\nAplicado el caso1\n\n";
	cout << "Raiz (Berni): " << avl->getRaiz()->getPalabra() << endl;
	cout << "HI (Alexis): " << avl->getRaiz()->getHI()->getPalabra() << endl;
	cout << "HD (Camila): " << avl->getRaiz()->getHD()->getPalabra() << endl;
	cout << "Camila->HI (Botero): " << avl->getRaiz()->getHD()->getHI()->getPalabra() << endl;
	cout << "Camila->HD (Fede): " << avl->getRaiz()->getHD()->getHD()->getPalabra() << endl;
	cout << "Alexis->HI (Alejo): " << avl->getRaiz()->getHI()->getHI()->getPalabra() << endl;
	cout << "Camila(2): " << avl->getRaiz()->getRepeticiones() << "Apariciones." << endl;
}

void caso2test(){
	Nodo *n = new Nodo("javier");
	AVL *avl = new AVL(n);
	cout << avl->search("javier", avl->getRaiz());
	avl->insertar("gonzalo",avl->getRaiz());
	avl->insertar("oscar",avl->getRaiz());
	avl->insertar("lucas",avl->getRaiz());
	avl->insertar("pablo",avl->getRaiz());
	avl->insertar("rodrigo",avl->getRaiz());
	avl->getRaiz()->balancear();
	cout << "Aplicado el caso 2";
	cout << "Raiz(oscar): " << avl->getRaiz()->getPalabra() << endl;
	cout << "HD(pablo): " << avl->getRaiz()->getHD()->getPalabra() << endl;
	cout << "HI(javier): " << avl->getRaiz()->getHI()->getPalabra() << endl;
	cout << "Javier -> Izq (gonzalo): " << avl->getRaiz()->getHI()->getHI()->getPalabra() << endl;
	cout << "Javier -> Der (lucas): " << avl->getRaiz()->getHI()->getHD()->getPalabra() << endl;
	cout << "Pablo -> Der (rodrigo): " << avl->getRaiz()->getHD()->getHD()->getPalabra() << endl;
	
}
