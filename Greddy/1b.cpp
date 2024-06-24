// Se tiene un buque mercante cuya capacidad de carga es de k toneladas y un 
//conjunto de contenedores c1, …, cn cuyos pesos respectivos son p1, …, pn
//(expresados también en toneladas). Teniendo en cuenta que la capacidad del 
//buque es menor que la suma total de los pesos de los contenedores: 
//b. Diseñe un algoritmo que intente maximizar el número de toneladas cargadas.
#include <iostream>
#include <vector>
#include <algorithm>

struct Contenedor {
    int peso;
    int indice;
};

bool compararPorPeso(const Contenedor& c1, const Contenedor& c2) {
    return c1.peso > c2.peso; // Cambio en la función de comparación
}

void cargarContenedores(int capacidadBuque, std::vector<Contenedor>& contenedores) {
    int pesoCargado = 0;

    // Ordenar los contenedores por peso en orden descendente
    std::sort(contenedores.begin(), contenedores.end(), compararPorPeso);

    for (const Contenedor& contenedor : contenedores) {
        if (pesoCargado + contenedor.peso <= capacidadBuque) {
            pesoCargado += contenedor.peso;
            std::cout << "Contenedor " << contenedor.indice << " cargado." << std::endl;
        } else {
            break;
        }
    }

    std::cout << "Peso total cargado: " << pesoCargado << " toneladas." << std::endl;
}

int main() {
    int capacidadBuque = 10; // Cambia el valor de acuerdo a tu problema
    std::vector<Contenedor> contenedores = {{7, 1}, {3, 2}, {4, 3}, {2, 4}, {5, 5}};

    cargarContenedores(capacidadBuque, contenedores);

    return 0;
}
