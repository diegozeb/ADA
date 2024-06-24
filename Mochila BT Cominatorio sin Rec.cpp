#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Nodo {
    int nivel;
    int pesoActual;
    int valorActual;
    bool incluir;
};

bool solucion(const Nodo& nodo, int n) {
    return nodo.nivel == n;
}

bool criterio(const Nodo& nodo, int capacidad) {
    return nodo.pesoActual <= capacidad;
}

bool mas_hermanos(const Nodo& nodo) {
    return nodo.incluir == false;
}

Nodo generar(const Nodo& nodo, bool incluir) {
    Nodo nuevo = nodo;
    nuevo.nivel++;
    nuevo.incluir = incluir;
    return nuevo;
}

Nodo retroceder(stack<Nodo>& pila) {
    Nodo nodo = pila.top();
    pila.pop();
    return nodo;
}

int mochilaCombinatoria(vector<int>& pesos, vector<int>& valores, int capacidad) {
    int n = pesos.size();
    int valorMaximo = 0;
    stack<Nodo> pila;

    Nodo nodoInicial = { 0, 0, 0, true };
    pila.push(nodoInicial);

    while (!pila.empty()) {
        Nodo nodo = retroceder(pila);

        if (nodo.nivel < n) {
            Nodo nuevoNodo = generar(nodo, true);
            nuevoNodo.pesoActual += pesos[nodo.nivel];
            nuevoNodo.valorActual += valores[nodo.nivel];
            if (criterio(nuevoNodo, capacidad)) {
                pila.push(nuevoNodo);
            }

            nuevoNodo = generar(nodo, false);
            if (criterio(nuevoNodo, capacidad)) {
                pila.push(nuevoNodo);
            }
        }
        else if (solucion(nodo, n)) {
            valorMaximo = max(valorMaximo, nodo.valorActual);
        }
    }
    return valorMaximo;
}

int main() {
    vector<int> pesos = { 1, 3, 4, 5 };
    vector<int> valores = { 1, 4, 5, 7 };
    int capacidad = 7;
    int valorMaximo = mochilaCombinatoria(pesos, valores, capacidad);
    cout << "Valor máximo en mochila (Árbol Combinatorio): " << valorMaximo << endl;
    return 0;
}

