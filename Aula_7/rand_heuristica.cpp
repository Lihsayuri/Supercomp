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


int main(){
	std::ofstream arquivo("resposta.txt", std::ios::app);

	vector<item>vec;
	int n;
	double capacidade;
	int peso = 0;

	cin >> n;
	cin >> capacidade;
	vector<int>resposta(n, 0.0);


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
 	std::default_random_engine generator(seed); 	
	std::binomial_distribution<int> distribution(1, 0.5);

	for (int i = 0; i < n; i++){
		int sorteio = distribution(generator); // gera número
		if ((peso + vec[i].peso) <= capacidade){
			resposta[vec[i].id] = sorteio*abs(rand()%2);
			peso += vec[i].peso;
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

// Testando com : ./heuristica2 < in1_a.txt . Vai escrever em resposta2.txt. Depois usuar o selecao (lembrar de trocar o resposta no código e de passar o in.txt)