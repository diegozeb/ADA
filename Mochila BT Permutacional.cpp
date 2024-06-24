#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mochilaPermutacional(vector<int>& pesos, vector<int>& valores, int capacidad, int pesoActual, int valorActual, int& valorMaximo, vector<bool>& usados) {
    if (pesoActual <= capacidad) {
        valorMaximo = max(valorMaximo, valorActual);
    }
    for (int i = 0; i < pesos.size(); i++) {
        if (!usados[i] && pesoActual + pesos[i] <= capacidad) {
            usados[i] = true;
            mochilaPermutacional(pesos, valores, capacidad, pesoActual + pesos[i], valorActual + valores[i], valorMaximo, usados);
            usados[i] = false;
        }
    }
}

int main() {
    vector<int> pesos = { 1, 3, 4, 5 };
    vector<int> valores = { 1, 4, 5, 7 };
    int capacidad = 7;
    int valorMaximo = 0;
    vector<bool> usados(pesos.size(), false);
    mochilaPermutacional(pesos, valores, capacidad, 0, 0, valorMaximo, usados);
    cout << "Valor máximo en mochila (Árbol Permutacional): " << valorMaximo << endl;
    return 0;
}

