#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Nodo {
    vector<int> asignacionActual;
    int pesoActual;
    int valorActual;
};

bool solucion(const Nodo& nodo, int n) {
    return nodo.asignacionActual.size() == n;
}

bool criterio(const Nodo& nodo, int capacidad) {
    return nodo.pesoActual <= capacidad;
}

Nodo generar(const Nodo& nodo, int siguienteItem, vector<int>& pesos, vector<int>& valores) {
    Nodo nuevo = nodo;
    nuevo.asignacionActual.push_back(siguienteItem);
    nuevo.pesoActual += pesos[siguienteItem];
    nuevo.valorActual += valores[siguienteItem];
    return nuevo;
}

Nodo retroceder(stack<Nodo>& pila) {
    Nodo nodo = pila.top();
    pila.pop();
    return nodo;
}

int mochilaPermutacional(vector<int>& pesos, vector<int>& valores, int capacidad) {
    int n = pesos.size();
    int valorMaximo = 0;
    stack<Nodo> pila;

    Nodo nodoInicial = { {}, 0, 0 };
    pila.push(nodoInicial);

    while (!pila.empty()) {
        Nodo nodo = retroceder(pila);

        if (solucion(nodo, n)) {
            valorMaximo = max(valorMaximo, nodo.valorActual);
        }
        else {
            for (int i = 0; i < n; i++) {
                if (find(nodo.asignacionActual.begin(), nodo.asignacionActual.end(), i) == nodo.asignacionActual.end()) {
                    Nodo nuevoNodo = generar(nodo, i, pesos, valores);
                    if (criterio(nuevoNodo, capacidad)) {
                        pila.push(nuevoNodo);
                    }
                }
            }
        }
    }
    return valorMaximo;
}

int main() {
    vector<int> pesos = { 1, 3, 4, 5 };
    vector<int> valores = { 1, 4, 5, 7 };
    int capacidad = 7;
    int valorMaximo = mochilaPermutacional(pesos, valores, capacidad);
    cout << "Valor máximo en mochila (Árbol Permutacional): " << valorMaximo << endl;
    return 0;
}
