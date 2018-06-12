#include <iostream>
#include <fstream>

using namespace std;

/* --- PROTOTYPE FUNCTIONS --- */
void leerArchivo(AVL *avl, string archivo);
void caso1test();
void caso2test();

int main(){
	string archivo;
	AVL * avl = new AVL();
	do{
		cout << "Ingrese el nombre del archivo a leer (incluya la extension): ";
		cin >> archivo;
	}while(archivo == "");
	leerArchivo(avl,archivo);
	avl->toPrint(avl->getRaiz());
}

void leerArchivo(AVL * avl, string archivo){
	string cadena;
	ifstream lector;
	lector.open(archivo.c_str());
	if(lector.fail()){
		cout << "\t\t***\tERROR AL LEER EL ARCHIVO\t***\t\t\n\n";
		cout << "(Revise que el archivo '" << archivo << "' existe en el directorio local)\n_";
		cin.ignore(1);
	}else{
		while(lector.good()){
			lector >> cadena;
			//añadir las palabras al arbol.
			if (avl->getRaiz() == NULL){
				cout << cadena << endl;
				avl->setRaiz(new Nodo(cadena));
			}else{
				cout << cadena << endl;
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
