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

// Vammos supor que sempre comece na cidade 0, e a partir dai vamos conectar as outras 9 cidades até chegar na cidade 0 novamente. 
// Uma possível abordagem gulosa para isso seria sempre selecionar a menor distância possível entre o próximo e o atual.

int main(){
    int n_cidades;
    cin >> n_cidades;

    vector<int> valor_inicial(n_cidades, 0);
    vector<vector<int>> distancias_das_cidades (n_cidades, valor_inicial);

    for (int i = 0; i < n_cidades; i++){
        for (int j =  0; j < n_cidades; j++){
            cin >> distancias_das_cidades[i][j]; 
            // cout << distancias_das_cidades[i][j] << " ";
        }
        // cout << "\n";
    } 

    // agora vamos criar um vetor para ir guardando o caminho das cidades e a distância total percorrida.

    vector<int>cidades_percorridas(n_cidades+1, 0); // vai ser n_cidades+1 porque temos, por exemplo, 10 cidades - mas a cidade de inicio e fim é a mesma. 
    int distancia_total = 0;

    int menor_distancia = 1000;
    int cidade_escolhida = 0;
    for (int i = 1; i < n_cidades; i++ ){   // vai percorrendo e preenchendo nosso amigo cidades_percorridas, vai até n_cidades porque o mais 1 tem que ser 0
        int cidade_analisada = cidades_percorridas[i-1];
        for (int j = 0; j < n_cidades; j++){
            if (distancias_das_cidades[cidade_analisada][j] < menor_distancia && find(cidades_percorridas.begin(), cidades_percorridas.end(), j) == cidades_percorridas.end()){
                menor_distancia = distancias_das_cidades[cidade_analisada][j];
                cidade_escolhida = j;
                cidades_percorridas[i] = cidade_escolhida;

            }
        }

        distancia_total+= menor_distancia;
        menor_distancia  = 1000;
    }

    // cout << distancias_das_cidades[cidades_percorridas[n_cidades-1]][0] << "\n";
    distancia_total += distancias_das_cidades[cidades_percorridas[n_cidades-1]][0] ;

    cout << "A distância total é " << distancia_total << endl;
    for (int i = 0; i < n_cidades+1; i++){
        cout << cidades_percorridas[i] << " ";
    }


    return 0;
}