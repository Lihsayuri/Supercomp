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
using std::endl;



int retorna_centro(vector<int> distancia_cidade, int n_cidades){
    int maior_distancia = 0;
    int centro = 0;
    for (int i = 0; i < n_cidades; i++){
        if (distancia_cidade[i] > maior_distancia){
            maior_distancia = distancia_cidade[i];
            centro = i;
        }
    }

    // cout << "AQUIII " << centro << "\n";
    return centro;

}



int main(){
    int n_cidades;
	int n_centros;

	cin >> n_cidades;
	cin >> n_centros;

	vector<int>cidade(n_cidades, 0);
    vector<vector<int>> vetor_distancias(n_cidades, cidade);  // matriz de distancias entre as cidades

    vector<int> centro_escolhidos(n_centros, 0);

    for (int i = 0; i < n_cidades; i++){
        for (int j = 0; j < n_cidades; j++){
            cin >> vetor_distancias[i][j];
        }
    }

    if (n_centros == 1){
        centro_escolhidos[0] = 0;
        cout << 0 << endl;
        for (int i = 0; i < n_cidades; i++){
            cout << 0 << " ";
        } 
        return 0;
    }

    centro_escolhidos[0] = 0;

    cout << 0 << " ";
    int novo_centro = 0;

    for (int j = 0; j < n_centros ; j++){    // Em relação aos centros
        vector<int> linha = vetor_distancias[centro_escolhidos[j]];
        novo_centro = retorna_centro(linha, n_cidades);
        
        if (find(centro_escolhidos.begin(), centro_escolhidos.end(), novo_centro) == centro_escolhidos.end()){ // se o find chegar até o final da lista, significa que ele não encontrou
            centro_escolhidos[j+1] = novo_centro;
            cout << "AQUIIII " << j+1 << "\n";
            cout << novo_centro << " ";
        }
    }

    cout << "\n";

    int min_distancia = 10000;
    for (int i = 0; i < n_cidades; i++){
        int centro = 0;
        for (int j = 0; j < n_centros; j++){
            if (vetor_distancias[i][centro_escolhidos[j]] <= min_distancia){
                min_distancia = vetor_distancias[i][centro_escolhidos[j]];
                centro = centro_escolhidos[j];
            }
        }
        min_distancia = 10000; // Resetando para o próximo nao pegar a distância minima do outro.
        cout << centro << " ";
    }

    return 0;
}
