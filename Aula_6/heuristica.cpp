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
	std::ofstream arquivo("resposta.txt", std::ios::app);
	vector<item>vec;
	int n;
	double capacidade;

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
	std::binomial_distribution<int> distribution(1, 0.75);

	for (int i = 0; i < n; i++){
		int heuristica = distribution(generator)*abs(rand()%2);
		resposta[i] = heuristica;
	}

	unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
 	std::default_random_engine generator2(seed2); 	
	std::binomial_distribution<int> distribution2(1,0.25);
	

	for (int i = 0; i < n; i++){
		int sorteio = distribution(generator2)*abs(rand()%2); // gera número
		if ((sorteio == 1) && (resposta[i] == 0)){
			resposta[i] = sorteio;
		} else if ((sorteio == 0) && (resposta[i] == 1)){
			resposta[i] = sorteio;
		}
	}


	if (arquivo.is_open()) {
		for (int i = 0; i < n; i++){
			arquivo << resposta[i] << " ";
		} 
		arquivo << "\n";
    	arquivo.close();
  	} else {
    	std::cout << "Erro ao abrir arquivo" << std::endl;
  	}

}
