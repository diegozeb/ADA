//Nuestra empresa desarrolla software para terminales de puntos de venta [TPV] y 
//desea que le añadamos la siguiente funcionalidad a nuestro sistema: 
//a. En su versión para máquinas expendedoras, se pretende minimizar el 
//número de monedas empleado para darle el cambio al cliente. Diseñe un 
//algoritmo greedy que devuelva un número mínimo de monedas (de 0.01, 
//0.02, 0.05, 0.10, 0.20, 0.50 y 1 euro). 
//b. Nuestra empresa también distribuye máquinas expendedoras de sellos de 
//correos (de 0.54, 0.32, 0.17 y 0.01 euros) y decidimos reutilizar nuestro 
//algoritmo greedy para decidir qué sellos ha de devolver la máquina. 
//Demuestre que el algoritmo greedy no proporciona necesariamente una 
//solución óptima, aun disponiendo de un suministro inagotable de sellos 
//de cada valor.
#include <iostream>
#include <vector>
using namespace std;
vector<int> vuelto(float dinero,vector<float>monedas) {
    vector<int> cambio;
    while (!monedas.empty()) {
        float x = monedas[0];
        auto y = monedas.begin();
        monedas.erase(y);
        int cont = 0;
        while (dinero >= x) {
            dinero = dinero - x;
            cont++;
        }
        cambio.push_back(cont);
    }
    return cambio;
}

int main(){
    float dinero = 25.69;
    vector<float>  monedas = {0.54,0.32,0.17,0.01};
    vector<int> cambio = vuelto(dinero,monedas);
    cout << "Para darle vuelto a mi causa:" << endl;
    for (int i = 0; i < cambio.size(); i++) {
        cout << "Necesito " << cambio[i] << " monedas de " << monedas[i] << endl;
    }
}