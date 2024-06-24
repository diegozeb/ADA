#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Nodo {
    vector<int> asignacionActual;
    int pesoActual;
    int valorActual;
    int nivel;
};

bool solucion(const Nodo& nodo, int n) {
    return nodo.nivel == n;
}

bool criterio(const Nodo& nodo, int capacidad) {
    return nodo.pesoActual <= capacidad;
}

Nodo generar(const Nodo& nodo, int siguienteItem, vector<int>& pesos, vector<int>& valores) {
    Nodo nuevo = nodo;
    nuevo.asignacionActual.push_back(siguienteItem);
    nuevo.pesoActual += pesos[siguienteItem];
    nuevo.valorActual += valores[siguienteItem];
    nuevo.nivel++;
    return nuevo;
}

Nodo masHermanos(const Nodo& nodo, int siguienteItem, vector<int>& pesos, vector<int>& valores) {
    Nodo nuevo = nodo;
    nuevo.asignacionActual.pop_back(); // Retroceder un nivel
    nuevo.pesoActual -= pesos[nodo.asignacionActual.back()];
    nuevo.valorActual -= valores[nodo.asignacionActual.back()];
    nuevo.nivel--; // Retroceder un nivel
    return generar(nuevo, siguienteItem, pesos, valores); // Generar el siguiente nodo hermano
}

int mochilaBinaria(vector<int>& pesos, vector<int>& valores, int capacidad) {
    int n = pesos.size();
    int valorMaximo = 0;
    stack<Nodo> pila;

    Nodo nodoInicial = { {}, 0, 0, 0 };
    pila.push(nodoInicial);

    while (!pila.empty()) {
        Nodo nodo = pila.top();
        pila.pop();

        if (solucion(nodo, n)) {
            valorMaximo = max(valorMaximo, nodo.valorActual);
        }
        else {
            if (nodo.nivel < n) {
                // Generar el hijo izquierdo (sin tomar el siguiente ítem)
                Nodo hijoIzquierdo = generar(nodo, nodo.nivel, pesos, valores);
                if (criterio(hijoIzquierdo, capacidad)) {
                    pila.push(hijoIzquierdo);
                }

                // Generar el hijo derecho (tomando el siguiente ítem)
                if (nodo.pesoActual + pesos[nodo.nivel] <= capacidad) {
                    Nodo hijoDerecho = generar(nodo, nodo.nivel, pesos, valores);
                    if (criterio(hijoDerecho, capacidad)) {
                        pila.push(hijoDerecho);
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
    int valorMaximo = mochilaBinaria(pesos, valores, capacidad);
    cout << "Valor máximo en mochila (Árbol Binario): " << valorMaximo << endl;
    return 0;
}

