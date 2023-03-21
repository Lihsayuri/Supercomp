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


int num_leaf = 0;
int num_copy = 0;
vector<item> melhor_mochila;
int melhor_mochila_valor = 0;


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

vector<item> knapsack(int i, vector<item> &vec, double &capacidade, vector<item> mochila, int total_disponivel, int valor_atual){
    if (peso_mochila(mochila) >= capacidade){
        return mochila;
    }

    if (i == 0){
        num_leaf++;
        if ((vec[i].peso + peso_mochila(mochila)) <= capacidade){
            mochila.push_back(vec[i]);
        }
        return mochila;
    }

    if (valor_atual < total_disponivel){
        total_disponivel -= vec[i].valor;
        vector<item> m1 = knapsack(i-1, vec, capacidade, mochila, total_disponivel, valor_atual);
        mochila.push_back(vec[i]);
        valor_atual += vec[i].valor;
        vector<item> m2 = knapsack(i-1, vec, capacidade, mochila, total_disponivel, valor_atual);
        
        if ((peso_mochila(m1) <= capacidade) && (peso_mochila(m2) <= capacidade)){
            if (valor_mochila(m1) > valor_mochila(m2)){
                if (valor_mochila(m1) > melhor_mochila_valor){
                    melhor_mochila = m1;
                    melhor_mochila_valor = valor_mochila(m1);
                    num_copy++;
                }
                return m1;
            }
            else{
                if (valor_mochila(m2) > melhor_mochila_valor){
                    melhor_mochila = m2;
                    melhor_mochila_valor = valor_mochila(m2);
                    num_copy++;
                }
                return m2;
            }
        }
        else if (peso_mochila(m1) <= capacidade){
            if (valor_mochila(m1) > melhor_mochila_valor){
                melhor_mochila = m1;
                melhor_mochila_valor = valor_mochila(m1);
                num_copy++;
            }
            return m1;
        }
        else if (peso_mochila(m2) <= capacidade){
            if (valor_mochila(m2) > melhor_mochila_valor){
                melhor_mochila = m2;
                melhor_mochila_valor = valor_mochila(m2);
                num_copy++;
            }
            return m2;
        }
        else{
            return mochila;
        }
    } else if(valor_atual == total_disponivel){
        if (valor_atual > melhor_mochila_valor){
            melhor_mochila = mochila;
            melhor_mochila_valor = valor_atual;
            num_copy++;
        }
    }

    return mochila;
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

    int total_disponivel = 0;
    for (int i = 0; i < int(vec.size()); i++){
        total_disponivel += vec[i].valor;
    }
    mochila = knapsack(n-1, vec, capacidade, mochila, total_disponivel, 0);

    // imprima os itens da mochila e o valor total

    for (int i = 0; i < int(mochila.size()); i++){
        cout << mochila[i].id << " ";
        valor += mochila[i].valor;
    }
    cout << "Valor: " << valor << "\n";

    cout << "num_leaf " << num_leaf << "\n";
    cout << "num_copy " << num_copy << "\n";

}