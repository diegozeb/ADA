//Dado un vector de n elementos, de los cuales algunos están duplicados, diseñe 
//un algoritmo O(n log n) que permita eliminar todos los elementos duplicados.
#include <iostream>
#include <vector>
using namespace std;

vector<int> merge (vector<int> fst, vector<int> scd){
    vector<int> sol;
    int i = 0;
    int j = 0;
    while (i < fst.size() && j < scd.size()) {
        if (fst[i] < scd[j]) {
            sol.push_back(fst[i]);
            i++;
        } else if (fst[i] > scd[j]) {
            sol.push_back(scd[j]);
            j++;
        } else {
            sol.push_back(fst[i]);
            i++;
            j++;
        }
    }
    while (i < fst.size()) {
            sol.push_back(fst[i]);
            i++;
        }

        while (j < scd.size()) {
            sol.push_back(scd[j]);
            j++;
        }
    
    return sol;
}

vector<int>erase(vector<int> toErase){
    vector<int> sol;
    if(toErase.size() == 1 )
        return toErase;
    int mid = (int) toErase.size()/2;
    vector<int>leftPart(toErase.begin(),toErase.begin()+mid);
    vector<int>rightPart(toErase.begin()+mid,toErase.end());
    leftPart = erase(leftPart);
    rightPart = erase(rightPart);
    sol = merge(leftPart, rightPart);
    return sol;
}

int main(int argc, const char * argv[]) {

    vector<int> first= {1,6,5,9,0,9,5,6,9};
    first= erase(first);
    for(int i = 0; i<first.size();i++)
        cout<<first[i]<<" ";
    cout<<endl;
    return 0;
}