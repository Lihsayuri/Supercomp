#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
// using std::vector

struct item{
	int id;
	double peso;
	double valor;
};

void mais_caro(){
	std::vector<item>vec;
	int n;
	double capacidade;

	std::cin >> n;
	std::cin >> capacidade;

	for (int i = 0; i < n; i++){
		item it;
		it.id = i;
		std::cin >> it.peso;
		std::cin >> it.valor;
		vec.push_back(it);
	}

	std::sort(vec.begin(), vec.end(), [] (const item &a, const item &b){
		return a.valor > b.valor;
	});

	double peso_final = 0;
	double valor_final = 0;
	std::vector<int>resposta(n, 0.0);

	int j = 0;
	for(int i =0; i < n; i++){
		if ((peso_final + vec[i].peso) <= capacidade){
			resposta[j] = vec[i].id;
			peso_final += vec[i].peso;
			valor_final += vec[i].valor;
			j++;
		}
	}

	resposta.resize(j);
	
	std::sort(resposta.begin(), resposta.end(), [] (const int &a, const int &b){
		return a < b;
	});

	std::cout << peso_final << " " << valor_final <<  " " << "0"  << "\n";
	for (int i = 0; i < j; i++){
		std::cout << resposta[i] << " ";
	}
}


void mais_leve(){
	std::vector<item>vec;
	int n;
	double capacidade;

	std::cin >> n;
	std::cin >> capacidade;

	for (int i = 0; i < n; i++){
		item it;
		it.id = i;
		std::cin >> it.peso;
		std::cin >> it.valor;
		vec.push_back(it);
	}

	std::sort(vec.begin(), vec.end(), [] (const item &a, const item &b){
		return a.peso < b.peso;
	});


	// std::cout << "OLHA AI A ORDENACAO: \n";
	// for (int i = 0; i < n; i++){
	// 	std::cout << vec[i].id << " " << vec[i].peso << " " << vec[i].valor << "\n";
	// }

	double peso_final = 0;
	double valor_final = 0;
	std::vector<int>resposta(n, 0.0);

	int j = 0;
	for(int i =0; i < n; i++){
		if ((peso_final + vec[i].peso) <= capacidade){
			resposta[j] = vec[i].id;
			peso_final += vec[i].peso;
			valor_final += vec[i].valor;
			j++;
		}
		else{
			break;
		}
	}

	resposta.resize(j);

	std::sort(resposta.begin(), resposta.end(), [] (const int &a, const int &b){
		return a < b;
	});

	std::cout << peso_final << " " << valor_final << " " << "0"  << "\n";

	for (int i = 0; i < j; i++){
		std::cout << resposta[i] << " ";
	}
}



int main(){

	std::cout << "Agora o mais caro: \n";
	mais_caro();

	std::cout << "\n";

	// std::cout << "Agora o mais leve: \n";
	// mais_leve();



}
