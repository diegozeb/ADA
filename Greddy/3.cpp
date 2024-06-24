//Tenemos que completar un conjunto de n tareas con plazos límite. Cada una de 
//las tareas consume la misma cantidad de tiempo (una unidad) y, en un instante 
//determinado, podemos realizar únicamente una tarea. La tarea i tiene como 
//plazo límite di
// y produce un beneficio gi
// (gi
// > 0) sólo si la tarea se realiza en un 
//instante de tiempo t ≤ di
//. 
//a. Diseñe un algoritmo greedy que nos permita seleccionar el conjunto de 
//tareas que nos asegure el mayor beneficio posible. 
//b. Aplique su algoritmo a la siguiente instancia del problema: 
//Tarea i 1 2 3 4 
 //Beneficio gi
 //50 10 15 30 
//Plazo límite di
 //2 1 2 1 
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

void solution(vector<pair<int, int>> Tareas) {
    vector <pair <int, int>> Solution;
    //Ordena tareas por placer
    sort(Tareas.begin(), Tareas.end(), [](pair<int, int> tarea1, pair<int, int> tarea2){
        return tarea1.first > tarea2.first;
        });

    for (pair<int, int> tarea : Tareas){
        // Selecciona la tarea con mayor beneficio
        Solution.push_back(tarea);

        // Verifica si la solución aún cumple con las reglas si la tarea seleccionada se agrega
        vector<pair<int, int>> tempSolution = Solution;
        
        //Ordena tareas por plazos de tempSolution
        sort(tempSolution.begin(), tempSolution.end(), [](pair<int, int> tarea1, pair<int, int> tarea2){
            return tarea1.second < tarea2.second;
        });

        //Si todos los indices de tempSolution cumplen con ejecutarse dentro de las restricciones
        //Set valid = false
        bool valid = true;
        int currentTime = 0;
        for (const pair<int, int>& task : tempSolution) {
            currentTime += 1;
            if (currentTime > task.second) {
                valid = false;
                break;
            }
        }
        //Si valid == false, entonces tempSolution rompe al menos una regla
        if (!valid) {
            // Quita la tarea recién agregada
            Solution.pop_back();
        }
    }
    //Ordenar solución
    sort(Solution.begin(), Solution.end(), [](pair<int, int> tarea1, pair<int, int> tarea2){
    return tarea1.second < tarea2.second;
    });
    
    // Printing the Solution vector
    for (const pair<int, int>& task : Solution) {
        cout << "(" << task.first << ", " << task.second << ")" << " ";
    }
    cout << endl;
}

int main(){
    vector <pair<int,int>> Tareas = {{20,3},{15,1},{10,1},{7,3}, {5,1},{3,3}};
    solution(Tareas);
    return 0;
}