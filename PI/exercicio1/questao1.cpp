#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <random>
#include <chrono>
#include <stdlib.h> 
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string> 
#include <string.h>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// Em relação a implementação, notei que a distância entre a última atividade e a primeira eram somadas, mas não fiz isso pois achei que não faz sentido.
// Ainda mais se estivermos pensando em limitações de custo, não faz sentido eu sair do último lugar no meu roteiro de atividades e voltar para o primeiro, 
// consumindo mais horas e na vida real, gastando mais com deslocamento.


double distance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371000;
    double phi1 = lat1 * M_PI / 180;
    double phi2 = lat2 * M_PI / 180;
    double dphi = (lat2 - lat1) * M_PI / 180;
    double dlambda = (lon2 - lon1) * M_PI / 180;
    double a = pow(sin(dphi / 2), 2) + cos(phi1) * cos(phi2) * pow(sin(dlambda / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;
    return distance;
}


int main(){
    int n_cidades;
    cin >> n_cidades;

    vector<double> vazio (2, 0);
    vector<vector<double>> vetor_lat_long(n_cidades, vazio);

    for (int i = 0; i < n_cidades; i++){
        for (int j = 0; j < 2; j++){
            cin >> vetor_lat_long[i][j];
        }
    }

    vector<double> vazio_distancia (n_cidades, 0.0);
    vector<vector<double>> vetor_distancias(n_cidades, vazio_distancia);

    for (int i = 0; i < n_cidades; i++){
        for (int j = 0; j < n_cidades; j++){
            // aqui ele vai calcular a distancia em relacao a cidade fixada em i (vamos supor, cidade 0) com as demais que vao desde ela mesma - distancia 0, até todas as outras
            double distancia = distance(vetor_lat_long[i][0], vetor_lat_long[i][1], vetor_lat_long[j][0], vetor_lat_long[j][1]);
            vetor_distancias[i][j] = distancia;
        }
    }


    vector<int>ordem_atividades;


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution_distances(0, n_cidades-1);
    int primeira_atividade = distribution_distances(generator);

    ordem_atividades.push_back(primeira_atividade);

    double menor_distancia = 10000000000000.0;
    double distancia_total = 0;
    int atividade_escolhida = 0;

    for (int i = 1; i < n_cidades; i++){
        int cidade_analisada = ordem_atividades[i-1];
        for (int j = 0; j < n_cidades; j++){
            if (vetor_distancias[cidade_analisada][j] < menor_distancia && find(ordem_atividades.begin(), ordem_atividades.end(), j) == ordem_atividades.end()){
                menor_distancia = vetor_distancias[cidade_analisada][j];
                atividade_escolhida = j;
            }
        }

        ordem_atividades.push_back(atividade_escolhida);
        distancia_total+= menor_distancia;
        menor_distancia = 10000000000000.0;
    }

    std::string resultado = std::to_string(distancia_total);

    cout << "Distância total percorrida: " << resultado << " metros" << endl;
    cout << "Ordem das atividades: " << endl;
    for (int i = 0; i < n_cidades; i++){
        if (i == n_cidades-1){
            cout << ordem_atividades[i]+1;
        } else{
            cout << ordem_atividades[i]+1 << " -> ";
        }
    }


    return 0;
}
