//Consideremos un grafo no dirigido G = (V, E). Un conjunto de nodos U se dice 
//que es un recubrimiento de G si U es un subconjunto de V tal que cada arista en 
//E incide en, al menos, un vértice de U. Un conjunto de nodos es un 
//recubrimiento minimal de G si es un recubrimiento con el número mínimo 
//posible de nodos. 
//a. Diseñe un algoritmo greedy para obtener un recubrimiento de G. 
//b. Indique si el algoritmo greedy devuelve un recubrimiento minimal para 
//cualquier grafo si, como función de selección, se escoge el nodo con 
//mayor grado de incidencia de entre los nodos aún no seleccionados. 
//NOTA: 
//El grado de incidencia de un vértice es el número de aristas que inciden en él.
#include <iostream>
#include <vector>
using namespace std;
struct Arista;
struct Nodo {
	char valor;
	vector<Arista> arista;
	Nodo(char a) {
		valor = a;
	}
};
struct Arista {
	vector<Nodo> extremos;
	Arista(Nodo A, Nodo B) {
		extremos.push_back(A);
		extremos.push_back(B);
	}
};
struct Grafo {
	vector<Nodo> nodos;
	vector<Arista> aristas;
	void insertarNodo(Nodo *A) {
		nodos.push_back(*A);
	}
	void insertarArista(Nodo* A, Nodo* B) {
		Arista E(*A, *B);
		(*A).arista.push_back(E);
		(*B).arista.push_back(E);
		aristas.push_back(E);
	}
};
vector<Nodo> Ordenar(vector<Nodo> Conjunto) {
	int i = 0, j = 1;
	while (i < Conjunto.size()) {
		if (Conjunto[i].arista.size() < Conjunto[j].arista.size()) {
			swap(Conjunto[i], Conjunto[j]);
		}
		j++;
		if (j == Conjunto.size()) {
			i++;
			j = i;
		}
	}
	return Conjunto;
}
bool factible(Nodo T, vector<Arista> &G) {
	bool borre = false;
	auto it = G.begin();
	while (it != G.end()) {
		if ((*it).extremos[0].valor == T.valor || (*it).extremos[1].valor == T.valor) {
			G.erase(it);
			it = G.begin();
			borre = true;;
		}
		else {
			++it;
		}
	}
	return borre;
}
vector<Nodo> recubrimiento(Grafo G) {
	vector<Nodo> Solucion;
	vector<Nodo> Conjunto = G.nodos;
	Conjunto = Ordenar(Conjunto);
	while (!G.aristas.empty()) {
		Nodo T = Conjunto[0];
		auto y = Conjunto.begin();
		Conjunto.erase(y);
		if (factible(T,G.aristas)) {
			Solucion.push_back(T);
		}
	}
	return Solucion;
}
int main(){
	Grafo G;
	Nodo* A = new Nodo('A');
	Nodo* B = new Nodo('B');
	Nodo* C = new Nodo('C');
	Nodo* D = new Nodo('D');
	Nodo* E = new Nodo('E');
	G.insertarArista(A, C);
	G.insertarArista(B, C);
	G.insertarArista(B, D);
	G.insertarArista(A, B);
	G.insertarArista(C, D);
	G.insertarArista(C, E);
	G.insertarArista(D, E);
	G.insertarNodo(A);
	G.insertarNodo(B);
	G.insertarNodo(C);
	G.insertarNodo(D);
	G.insertarNodo(E);
	vector<Nodo> R = recubrimiento(G);
	for (int i = 0;i<R.size(); i++) {
		cout<< R[i].valor << " ";
	}
}