//Diseñe un algoritmo "divide y vencerás" que permita calcular el k−ésimo menor 
//elemento de un vector.
#include <iostream>
#include <vector>
using namespace std;


int Quickselect(vector<int> arr, int k) {
    //este esta pa terminar la recursividad y bueno como solo hay un simbolo pues este sera el pivote y estaria en lo de iguales asi q nos ahorramos todo
    if (arr.size() == 1) {
        return arr[0];
    }
    //agarraremos siempre el ultimo, pero en verdad es como el quicksort, podemos elegir el que queremos
    int pivote = arr[arr.size() - 1];

    vector<int> menores;
    vector<int> iguales;
    vector<int> mayores;

    //dividimos el vector en 3 segun el pivote q toco
    for (auto i = arr.begin(); i != arr.end(); i++) {
        if (*i < pivote) {
            menores.push_back(*i);
        }
        else if (*i == pivote) {
            iguales.push_back(*i);
        }
        else { mayores.push_back(*i); }

    }
    //de ahi nuestro k q es el k_esimo menor numero q queremos lo comparamos con esos 3 vectores
    // 
    //Este el de menores, si K se encuentra en este significa q debe ser uno de ese array ya
    //ya que al dividirlos por menores iguales y mayores, medio ya esta ordenado y podemos saber q si
    //ese k enesimo no supera la longitud de los menores es porque debe estar ahi 
    if (k <= menores.size()) { return Quickselect(menores, k);}//despues volvemos a hacer el quick select para buscar de nuevo ese k entre el array de menores

    //Este es el de iguales, aqui digamos nuestro array tiene repetidos, pues entre esos da igual cual se seleccione ya q serian igual los k_esimos
    //para entrar a este tenemos q ver q bueno sean mas grandes q menores, eso lo sabemos porque si paso la primera parte pues es verdad y de ahi tambien
    //vemos q se compara con el tamaño de menores mas iguales, esto nos permite darnos cuenta q si llego es xq no debe estar en los menores y debe estar en el vector de iguales
    //y si esta en el vector de iguales pues da igual cual escoger, ademas q sabemos q iguales es el pivote xq gracias a el los separamos
    else if (k <= menores.size() + iguales.size()) { return pivote; }

    //En este if es cuando ya pues no entro en ninguno lo q significa q ese k no se encuentra ni entre los menores ni los iguales, por lo q haremos la busqueda de nuevo pero en el de mayores 
    //eso si aqui a diferencia de el de menores pues restaremos valor a k, exactamente digamos queremos el quinto valor,k=5  y vimos q no esta en menores e iguales y digamos estos en total eran 4 
    //numeros, pues no vamos a seguir con esa k=5 sino q vamos a restar esas 4 posiciones q sabemos no estan osea ahora tendriamos q encontrar el menor en ese array este es un ejemplo pero espero q ayude
    //a darse una guia, recomiendo dibujar
    else { return Quickselect(mayores, k - menores.size() - iguales.size()); }

}

int main()
{

    vector<int>lista = { 5,18,2,4,9,5,65,1,7,3 };
    int respuesta = Quickselect(lista, 7);
    cout << respuesta;
}