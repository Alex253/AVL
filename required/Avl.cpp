#include "Nodo.cpp"
#include <string>

using namespace std;
class AVL{
	private:
		Nodo * raiz;
		
	public:
		//Constructores
		AVL();
		AVL(Nodo * n);
		AVL(string palabra);
		void guardarArchivo();
		
		//metodos generales
		string toPrint(Nodo *n, string cadena);
		bool search(string p, Nodo * origen);
		void balancear(Nodo * nod);
		void insertar(string p, Nodo * origen);
		void graph(Nodo *nodo, int n){
			int i;
			if(nodo != NULL){
				graph(nodo->getHD(), n+1);
				for (i = 1 ; i <= n ; i++){
					cout << "\t\t";
				}
				cout << nodo->getPalabra() << "\n";
				graph(nodo->getHI(), n+1);
			}
		}
		
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

void AVL::guardarArchivo(){
	string nombre = "";
	do{
		cout << "Ingrese el nombre del archivo para guardar: ";
		cin >> nombre;
	}while(nombre == "");
	ofstream salida(nombre.c_str());
	salida << this->toPrint(this->getRaiz(),"");
	salida.close();
}

string AVL::toPrint(Nodo * n, string cadena = ""){
	//IMPRIME IZQUIERDA, NODO, DERECHA (ORDEN ALFABETICO)
	if(n != NULL){
		//agrega el hijo izquierdo
		cadena.append(toPrint(n->getHI(), ""));
		//cout << "\n" << n->getPalabra() << "(" <<n->getRepeticiones() << ")" << endl;
		//se agrega a si mismo
		cadena.append(n->getPalabra())
		 .append(":\t")
		 .append(to_string(n->getRepeticiones()))
		 .append("\n");
		//agrega al hijo derecho
		cadena.append(toPrint(n->getHD(), ""));
	}
	return cadena;
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
		nod->balancear();
		this->balancear(nod->getHD());
		
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
