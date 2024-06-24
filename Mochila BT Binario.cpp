#include <iostream>
#include <vector>
using namespace std;

int mochilaBinaria(int i, int pesoActual, int valorActual, int capacidad, const vector<int>& pesos, const vector<int>& valores) {
    if (i == pesos.size()) {
        return valorActual;
    }
    int valorSinActual = mochilaBinaria(i + 1, pesoActual, valorActual, capacidad, pesos, valores);
    int valorConActual = valorActual;
    if (pesoActual + pesos[i] <= capacidad) {
        valorConActual = mochilaBinaria(i + 1, pesoActual + pesos[i], valorActual + valores[i], capacidad, pesos, valores);
    }
    return max(valorConActual, valorSinActual);
}

int main() {
    vector<int> pesos = { 1, 3, 4, 5 };
    vector<int> valores = { 1, 4, 5, 7 };
    int capacidad = 7;
    int valorMaximo = mochilaBinaria(0, 0, 0, capacidad, pesos, valores);
    cout << "Valor máximo en mochila (Árbol Binario): " << valorMaximo << endl;
    return 0;
}
