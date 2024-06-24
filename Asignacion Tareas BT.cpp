#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Función recursiva para encontrar la asignación mínima de tareas usando backtracking
void asignarTareas(int trabajador, vector<vector<int>>& costos, vector<bool>& tareasAsignadas, int costoActual, int& costoMinimo) {
    int n = costos.size();

    // Si todas las tareas han sido asignadas
    if (trabajador == n) {
        costoMinimo = min(costoMinimo, costoActual);
        return;
    }

    // Probar asignar cada tarea al trabajador actual
    for (int tarea = 0; tarea < n; ++tarea) {
        if (!tareasAsignadas[tarea]) {
            tareasAsignadas[tarea] = true;
            asignarTareas(trabajador + 1, costos, tareasAsignadas, costoActual + costos[trabajador][tarea], costoMinimo);
            tareasAsignadas[tarea] = false;
        }
    }
}

int main() {
    // Ejemplo de matriz de costos
    vector<vector<int>> costos = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int n = costos.size();
    vector<bool> tareasAsignadas(n, false);
    int costoMinimo = INT_MAX;

    // Llamar a la función recursiva para asignar tareas
    asignarTareas(0, costos, tareasAsignadas, 0, costoMinimo);

    cout << "El costo mínimo de asignar las tareas es: " << costoMinimo << endl;

    return 0;
}