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


struct Melhor_mochila{
    vector<item> itens;
    double peso;
    double valor;
};


int num_leaf = 0;
int num_copy = 0;
Melhor_mochila melhor_mochila;

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

void knapsack(int i, vector<item> &vec, double &capacidade, vector<item> mochila, int potencial){
    if (valor_mochila(mochila) > melhor_mochila.valor && peso_mochila(mochila) <= capacidade){
        melhor_mochila.itens = mochila;
        melhor_mochila.valor = valor_mochila(mochila);
        melhor_mochila.peso = peso_mochila(mochila);
        num_copy++;
    }

    if (melhor_mochila.valor >= potencial && i == int(vec.size())-1){  // potencial  contém o atual mais o valor dos itens que ainda não foram considerados
        num_leaf++;
        return;
    } else if (melhor_mochila.valor >= potencial && i != int(vec.size())-1) {
        return;
    }

    if (peso_mochila(mochila) > capacidade){
        return;
    }  

    // cout << "CHEGUEI AQUI"  ;

    knapsack(i+1, vec, capacidade, mochila, potencial-vec[i].valor);
    mochila.push_back(vec[i]);
    knapsack(i+1, vec, capacidade, mochila, potencial);

}

int main(){
	vector<item>vec;
	int n;
	double capacidade;

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

    int total_disponivel = 0;
    for (int i = 0; i < int(vec.size()); i++){
        total_disponivel += vec[i].valor;
    }


    melhor_mochila.valor = 0;
    melhor_mochila.peso = 0;
    melhor_mochila.itens = mochila;

    cout << "total_disponivel " << total_disponivel << "\n";
    knapsack(0, vec, capacidade, mochila, total_disponivel);

    // imprima os itens da mochila e o valor total

    for (int i = 0; i < int(melhor_mochila.itens.size()); i++){
        cout << "ITEM: " <<melhor_mochila.itens[i].id << " " << "PESO: " <<melhor_mochila.itens[i].peso << " ";
    }
    cout << "Valor: " << melhor_mochila.valor << "\n";

    cout << "Peso: " << melhor_mochila.peso << "\n";

    cout << "num_leaf " << num_leaf << "\n";
    cout << "num_copy " << num_copy << "\n";

}