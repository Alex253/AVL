#include <iostream>
#include <fstream>
#include "required/Avl.cpp"

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
	//avl->toPrint(avl->getRaiz()); //El metodo ya no imprime
	avl->guardarArchivo();
	
	//cout << "\n---\n$:> " << avl->getRaiz()->getPalabra();
	//cout << "\n\n\t***GRAPH***\n\n";
	//avl->graph(avl->getRaiz(),0);
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

