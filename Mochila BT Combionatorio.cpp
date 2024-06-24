#include <iostream>
#include <vector>
using namespace std;

void mochilaCombinatoria(int i, int pesoActual, int valorActual, int capacidad, const vector<int>& pesos, const vector<int>& valores, int& valorMaximo) {
    if (pesoActual <= capacidad) {
        valorMaximo = max(valorMaximo, valorActual);
    }
    if (i == pesos.size() || pesoActual > capacidad) {
        return;
    }
    // Incluye el ítem actual
    mochilaCombinatoria(i + 1, pesoActual + pesos[i], valorActual + valores[i], capacidad, pesos, valores, valorMaximo);
    // No incluye el ítem actual
    mochilaCombinatoria(i + 1, pesoActual, valorActual, capacidad, pesos, valores, valorMaximo);
}

int main() {
    vector<int> pesos = { 1, 3, 4, 5 };
    vector<int> valores = { 1, 4, 5, 7 };
    int capacidad = 7;
    int valorMaximo = 0;
    mochilaCombinatoria(0, 0, 0, capacidad, pesos, valores, valorMaximo);
    cout << "Valor máximo en mochila (Árbol Combinatorio): " << valorMaximo << endl;
    return 0;
}
