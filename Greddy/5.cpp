//Supongamos que un único camarero debe atender a n clientes de un restaurante 
//y atender al cliente i-ésimo requiere un tiempo ti
//. La satisfacción de un cliente es 
//inversamente proporcional a su tiempo de espera y la propina que recibirá el 
//camarero dependerá de la satisfacción del cliente (si el cliente i espera wi
//minutos, la propina que dará al camarero será pi=1/wi). 
//a. Diseñe un algoritmo greedy para maximizar las ganancias del camarero y 
//demuestre si el algoritmo diseñado devuelve siempre la solución óptima 
//[o encuentre un contraejemplo que muestre que no lo hace]. 
//b. Nuestro restaurante toma la decisión de contratar a más camareros para 
//reducir el tiempo de espera de sus clientes. Modifique el algoritmo 
//anterior para maximizar las propinas de k camareros.
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

struct Cliente {
	int tiempo_servicio;
	Cliente(int tiempo) {
		tiempo_servicio = tiempo;
	}
};

struct Empleado {
	float ganancia_total = 0;
	float tiempo_espera_total = 0;
};

bool comparar(Cliente A, Cliente B) {
	return A.tiempo_servicio < B.tiempo_servicio;
}

float maximizar_ganancia(vector<Cliente>clientes) {
	sort(clientes.begin(), clientes.end(), comparar);
	float tiempo_espera_total = 0;
	float ganancia_total = 0;
	double propina = 0;
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		tiempo_espera_total += i->tiempo_servicio;
		propina = 1 / tiempo_espera_total;
		ganancia_total += propina;
	}
	return ganancia_total;
}
//el algoritmo voraz siempre sera mas eficiente debido a que la propina al ser inversamente proporcional al tiempo de espera total pues si lo ordenamos de menor a mayor siempre se sacara la maxima ganancia


void maximizar_ganancia_kempleados(vector<Cliente>clientes, vector<Empleado>&empleados) {
	sort(clientes.begin(), clientes.end(), comparar);
	double propina = 0;
	for (int i = 0; i < clientes.size(); i++) {
		int j = i % empleados.size(); // para q cuando la cantidad de clientes supera a la cantidad de empleados pues comenzara desde el inicio y asi
		empleados[j].tiempo_espera_total += clientes[i].tiempo_servicio;
		propina = 1 / empleados[j].tiempo_espera_total;
		empleados[j].ganancia_total += propina;
	}
}


// a la firme el main lo hice con bing xd da flojera crear ejemplos
int main() {
	srand(time(0));
	vector<Cliente> clientes;
	for (int i = 0; i < 1000; ++i) {
		int tiempo_servicio = rand() % 10 + 1; 
		clientes.push_back(Cliente(tiempo_servicio));
	}

	vector<Empleado> empleados(10);

	float ganancia = maximizar_ganancia(clientes);
	cout << "La ganancia máxima para un solo camarero es: " << ganancia << endl;

	maximizar_ganancia_kempleados(clientes, empleados);
	for (int i = 0; i < empleados.size(); ++i) {
		cout << "La ganancia total del empleado " << (i + 1) << " es: " << empleados[i].ganancia_total << endl;
	}

	return 0;
}