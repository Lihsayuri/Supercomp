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

// Nesse documento, adoto como heuristica o maior valor. Dessa forma, se minha mochila tem n itens, 0.75 (arredondado) dos itens vai seguir 
// a heuristica de maior valor. Os outros 0.25 (arredondado) vão seguir a aleatoriedade.


struct item{
	int id;
	double peso;
	double valor;
};


vector<item> knapsack(vector<item> vec, int capacidade, int tries){
	int peso = 0;
	melhor.reserve(n)
	mochila.reserve(n);


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
 	std::default_random_engine generator(seed); 	
	std::binomial_distribution<int> distribution(1, 0.5);

	for (int t = 0; t < tries; t++){
		for (int i = 0; i < n; i++){
			int sorteio = distribution(generator); // gera número
			if ((sorteio*abs(rand()%2)) == 1  && (peso + vec[i].peso) <= capacidade){
				mochila[i] = vec[i];
				peso += vec[i].peso;
			} else {
				mochila[i].id = 0;
			}
		}

		double valor = 0.0;
		for (int i=0; i <n ; i++){
			if (mochila[i].id == 1){
				valor += mochila[i].valor;
			}
		}

		if (valor > melhor_valor){
			melhor = mochila;
			max = valor;
		}

		return melhor;


	}
}

int main(){
	int n;
	double capacidade;
	cin >> n;
	cin >> capacidade;

	vector<item>vec;
	vector<item> melhor;
	vec.reserve(n);

	for (int i =0; i < n; i++){
		double peso, valor;
		cin >> peso;
		cin >> valor;
		vec.push_back({i, peso, valor});
	}

	melhor = knapsack(vec, capacidade, 10);

	return 0;


}

// Testando com : ./heuristica2 < in1_a.txt . Vai escrever em resposta2.txt. Depois usuar o selecao (lembrar de trocar o resposta no código e de passar o in.txt)