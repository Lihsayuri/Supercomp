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

int main(){
    int n_cidades;
    int n_centros;

    cin >> n_cidades >> n_centros;

    vector<int> cidades(n_cidades, 0);
    vector<vector<int>> distancias_das_cidades (n_cidades, cidades);

    for (int i = 0; i < n_cidades; i++){
        for (int j = 0; j < n_cidades; j++){
            cin >> distancias_das_cidades[i][j];
        }
    }

    // olhando para a lista de centros, sei que o primeiro vai ser 0. Então vou na cidade 0 e escolho a maior distância e guardo o novo centro. Depois vou pro
    // próximo centro.

    if (n_centros == 1){
        cout << 0 << "\n";
        for (int i = 0; i < n_cidades; i++){
            cout << 0 << " ";
        }
        return 0;
    }


    vector<int> centros(n_centros, 0);
    cout << centros[0] << " ";

    int maior_distancia = 0;
    int centro = 0;
    for (int k = 1; k < n_centros; k++){
        vector<int> cidade_analisada = distancias_das_cidades[centros[k-1]];  // com base no anterior, preencho o atual
        for (int j = 0; j < n_cidades; j++){
            if ((cidade_analisada[j] > maior_distancia) && (find(centros.begin(), centros.end(), j)) == centros.end()){
                // cout << "CIDADE ANALISADA " << cidade_analisada[j] << "\n";
                maior_distancia = cidade_analisada[j];
                centro = j;
                centros[k] = centro;
            }
        }
        maior_distancia = 0;
        cout << centros[k] << " ";

    }


    cout << "\n";

    // definindo os centros para as cidades com base na menor distância
    int menor_distancia = 100000;
    centro = 0;
    for (int i = 0; i < n_cidades; i++){
        vector<int> cidade_analisada = distancias_das_cidades[i];  // fixo uma cidade para analisar
        for (int k = 0; k < n_centros; k++){
            // cout << "CIDADE ANALISADA " << cidade_analisada[centros[k]] << "\n";
            // cout << "MENOR DISTANCIA " << menor_distancia << "\n";
            if (cidade_analisada[centros[k]] < menor_distancia){
                menor_distancia = cidade_analisada[centros[k]];
                centro = centros[k];
            }
        }
        menor_distancia = 100000;
        cout << centro << " ";
    }


    // for (int i = 0; i < n_cidades; i++){
    //     for (int j = 0; j < n_cidades; j++){
    //         cout << distancias_das_cidades[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}




// EXAMPLE:
//     std::vector<int> v = { 4, 7, 5, 2, 6, 9 };
//     int key = 6;
 
//     if (std::find(v.begin(), v.end(), key) != v.end()) {
//         std::cout << "Element found";
//     }
//     else {
//         std::cout << "Element not found";
//     }