#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <random>
#include <chrono>
#include <stdlib.h> 
#include <fstream>
using std::vector;
using std::cin;
using std::cout;

// Nesse documento, adoto como heuristica o binomial. 
// A heuristica binomial é uma heuristica que gera um número aleatório
// entre 0 e 1. Na primeira vez ele tem 0.75 de chance de gerar 1 e 0.25 de chance de gerar 0.
// Na segunda vez, ele tem 0.25 de chance de gerar 1 e 0.75 de chance de gerar 0.

struct item{
	int id;
	double peso;
	double valor;
};

int peso_mochila(vector<item> mochila){
    int peso = 0;
    for (int i = 0; i < int(mochila.size()); i++){
        peso += mochila[i].peso;
    }
    return peso;
}

int valor_mochila(vector<item> mochila){
    int valor = 0;
    for (int i = 0; i < int(mochila.size()); i++){
        valor += mochila[i].valor;
    }
    return valor;
}

vector<item> knapsack(int i, vector<item> &vec, double &capacidade, vector<item> mochila){
    if (peso_mochila(mochila) >= capacidade){
        return mochila;
    }

    if (i == 0){
        if ((vec[i].peso + peso_mochila(mochila)) <= capacidade){
            mochila.push_back(vec[i]);
        }
        return mochila;
    }

    vector<item> m1 = knapsack(i-1, vec, capacidade, mochila);
    mochila.push_back(vec[i]);
    vector<item> m2 = knapsack(i-1, vec, capacidade, mochila);

    if ((peso_mochila(m1) <= capacidade) && (peso_mochila(m2) <= capacidade)){
        if (valor_mochila(m1) > valor_mochila(m2)){
            return m1;
        }
        else{
            return m2;
        }
    }
    else if (peso_mochila(m1) <= capacidade){
        return m1;
    }
    else if (peso_mochila(m2) <= capacidade){
        return m2;
    }
    else{
        return mochila;
    }
}

int main(){
	vector<item>vec;
	int n;
	double capacidade;
	int valor = 0;

	cin >> n;
	cin >> capacidade;
	vector<int>resposta(n, 0.0);

    cout << "capacidade " << capacidade << "\n";
    cout << "n " << n << "\n";


	for (int i = 0; i < n; i++){
		item it;
		it.id = i;
		cin >> it.peso;
		cin >> it.valor;
		vec.push_back(it);
	}

    vector<item> mochila;
    mochila = knapsack(n-1, vec, capacidade, mochila);

    // imprima os itens da mochila e o valor total

    for (int i = 0; i < int(mochila.size()); i++){
        cout << mochila[i].id << " ";
        valor += mochila[i].valor;
    }
    cout << "Valor: " << valor << "\n";

}