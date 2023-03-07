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

void mais_caro(vector<item>&vec, int &n, double &capacidade){
	std::sort(vec.begin(), vec.end(), [] (const item &a, const item &b){
		return a.valor > b.valor;
	});
}

int main(){
	std::ofstream arquivo("mochila_completa.txt", std::ios::app);
	vector<item>vec;
	int n;
	double capacidade;
	int valor = 0;

	cin >> n;
	cin >> capacidade;
	vector<int>resposta(n, 0.0);

	for (int i = 0; i < n; i++){
		item it;
		it.id = i;
		cin >> it.peso;
		cin >> it.valor;
		vec.push_back(it);
	}


	//int seed = 10;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
 	std::default_random_engine generator(seed); 	
	std::binomial_distribution<int> distribution(1, 0.5);

	for (int i = 0; i < n; i++){
		int sorteio = distribution(generator)*abs(rand()%2);
		if (sorteio == 1 && vec[i].peso <= capacidade){
			resposta[i] = sorteio;
			valor+= vec[i].valor;
		}
	}

    for (int i = 0; i < n ; i++){
        int sorteio = distribution(generator)*abs(rand()%2);
		if (sorteio == 1 && vec[i].peso <= capacidade && resposta[i] == 0){
			resposta[i] = sorteio;
			valor+= vec[i].valor;
		}
    }

	if (arquivo.is_open()) {
		for (int i = 0; i < n; i++){
			arquivo << resposta[i] << " ";
		} 
		arquivo << "Valor: " << valor << "\n";

		arquivo << "\n";
    	arquivo.close();
  	} else {
    	std::cout << "Erro ao abrir arquivo" << std::endl;
  	}

}