//Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi 
//requiere Si
// megabytes de espacio y la capacidad del disco es D megabytes, 
//siendo D < ΣSi
//. Resuelva las siguientes cuestiones: 
//a. Diseñe un algoritmo greedy que maximice el número de programas 
//almacenados en el disco (existe un algoritmo que proporciona una 
//solución óptima). 
//b. Diseñe un algoritmo greedy que intente aprovechar al máximo la 
//capacidad del disco (demuestre que podemos utilizar un algoritmo 
//greedy que seleccione los programas por orden no creciente para obtener 
//la solución exacta o encuentre un contraejemplo de lo contrario). 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> max_programs(vector<int> pesos, int limite){
    int count = 0;
    vector <int> res;
    //Ordenar los pesos de menor a mayor
    sort(pesos.begin(), pesos.end(), less());
    //Recorrer los pesos
    for(int i = 0; i < pesos.size(); i++){
        //Si la suma es mayor al límite, retornar los pesos hasta ahí
        if ((count + pesos[i]) >= limite){
            //Insertar en el vector res el vector pesos[:i]
            res.insert(res.end(), pesos.begin(), pesos.begin() + i);
            return res;
        }
        //Caso contrario, sumar los pesos
        count = count + pesos[i];
    }
    //Por si no retorna nada
    return res;
}

int main(){
    vector <int> pesos = {4, 1, 6, 8, 2, 10, 22};
    vector <int> contraejemplo = {22,30};
    /*
    En el caso del contraejemplo
    - Solo usaria 22
    - Pero podría usar 30 y estaría siendo mas eficiente
    */
    int limite = 30;
    vector<int> res = max_programs(pesos, limite);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}