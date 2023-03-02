#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <random>
#include <chrono>
#include <stdlib.h> 
#include <fstream>
#include <string>
using std::vector;
using std::cin;
using std::cout;

struct item{
	int id;
	double peso;
	double valor;
};

int main(){

	int n;
    double capacidade;

	cin >> n;
	cin >> capacidade;

    cout << "Capacidade: " << capacidade << "\n";
    cout << "N: " << n << "\n";


    vector<item>vec;

	for (int i = 0; i < n; i++){
		item it;
		it.id = i;
		cin >> it.peso;
		cin >> it.valor;
		vec.push_back(it);
	}



    vector<vector<int>> resposta;
    std::ifstream arquivo("resposta2.txt", std::ios::in);
    if (arquivo.is_open()) {
        std:: string linha;
        while (getline(arquivo, linha)) {
            std::vector<int> linha_resposta;
            // cout << linha.size() << "\n";
            for (int i = 0; i < int(linha.size()); i++){
                if (linha[i] == '1'){
                    linha_resposta.push_back(i/2);
                }
            }
            resposta.push_back(linha_resposta);
        }
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir arquivo" << std::endl;
    }

    // for (int i = 0; i < int(resposta.size()); i++){
    //     for (int j = 0; j < int(resposta[i].size()); j++){
    //         std::cout << resposta[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }


    // Percorre todos os vetores de resposta, que são vetores dos ids dos itens e verifica se a soma dos pesos (através de vec) é menor que a capacidade.
    // Se for, adiciona esse vetor no vetor de vetores chamado resposta_final.

    vector<vector<int>> resposta_final;


    for (int i = 0; i < int(resposta.size()); i++){
        double soma_peso = 0;
        for (int j = 0; j < int(resposta[i].size()); j++){
            soma_peso += vec[resposta[i][j]].peso;
        }
        // cout << "Peso : " << soma_peso << "\n";

        if (soma_peso <= capacidade){
            resposta_final.push_back(resposta[i]);
        }
    }


    std::cout << "O tamanho de resposta_final (possíveis respostas válidas para mochila) é: " << resposta_final.size() << "\n";

    // Se o tamanho de resposta_final for 0, significa que não há solução válida para a mochila.
    if (resposta_final.size() == 0){
        std::cout << "Não há solução válida para a mochila.\n";
        return 0;
    }

    // Agora percorre todos os vetores de resposta_final e calcula o valor total de cada um deles. Escolhe o maior valor.

    double maior_valor = 0;
    int indice_maior_valor = 0;
    for (int i = 0; i < int(resposta_final.size()); i++){
        double soma_valor = 0;
        for (int j = 0; j < int(resposta_final[i].size()); j++){
            soma_valor += vec[resposta_final[i][j]].valor;
        }
        if (soma_valor > maior_valor){
            maior_valor = soma_valor;
            indice_maior_valor = i;
        }
    }

    std::cout << "O maior valor é: " << maior_valor << "\n";
    std::cout << "O peso é: " << capacidade << "\n";
    std::cout << "O vetor de resposta é: ";
    for (int i = 0; i < int(resposta_final[indice_maior_valor].size()); i++){
        std::cout << resposta_final[indice_maior_valor][i] << " ";
    }
    std::cout << "\n";

    return 0; 
}