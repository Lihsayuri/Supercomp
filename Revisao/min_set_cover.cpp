#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <random>
#include <chrono>
#include <stdlib.h> 
#include <fstream>
#include <iomanip>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;



void ordena_crescente(vector<int> &I){
    std::sort(I.begin(), I.end(), [] (int &a, int &b){
		return a < b;
	});

}


int main(){    
    vector<vector<int>> sets = {{4, 1, 3}, {2, 5}, {1, 4, 3, 2}};
    vector<int> custo = {5, 10, 3};

    // vector<vector<int>> sets = {{1, 2}, {2, 3, 4, 5}, {6, 7, 8, 9, 10, 11, 12, 13}, {1, 3, 5, 7, 9, 11, 13}, {2, 4, 6, 8, 10, 12, 13}};
    // vector<int> custo = {2, 2, 2, 2, 2};

    int n_sets = int(sets.size()); 
    vector <int> Universo;

    for (int i = 0; i < n_sets; i++){
        for (int j = 0; j < int(sets[i].size()); j++){
            if (find(Universo.begin(), Universo.end(), sets[i][j]) == Universo.end()){
                Universo.push_back(sets[i][j]);
            }
        }
    } 

    ordena_crescente(Universo);
    // for (int i = 0; i < int(Universo.size()); i++){
    //         cout << Universo[i] << " ";
    // } 

    vector<int> I;
    vector<int> sets_resposta;
    int custo_final = 0;


    int contribuicao = 0;
    float menor_custo = 1000.0;
    int set_escolhido = 0;

    while (I != Universo){
        for (int i = 0; i < n_sets;  i++){
            vector<int> conjunto_analisado = sets[i];
            for (int j = 0; j < int(conjunto_analisado.size()); j++){
                if (find(I.begin(), I.end(), conjunto_analisado[j]) == I.end()){
                    contribuicao += 1;
                }

            } 

            // cout << "MENOR CUSTO " << menor_custo << "\n";
            // cout << "CUSTO : " << custo[i] << "\n";
            // cout << "CONTRIB" << contribuicao << "\n";

            if (contribuicao != 0){
                // cout << "PROPORCAO do SET " << i << " : " ;
                // cout << setprecision(2) << (float)custo[i]/(float)contribuicao  <<  "\n";
                if ((((float)custo[i]/(float)contribuicao) < menor_custo) && (find(sets_resposta.begin(), sets_resposta.end(), i) == sets_resposta.end())){
                    menor_custo = ((float)custo[i]/(float)contribuicao);
                    set_escolhido = i;
                }
            }

            contribuicao = 0;
        }

        menor_custo = 1000;


        for (int i = 0; i < int(sets[set_escolhido].size()); i++){
            if (find(I.begin(), I.end(), sets[set_escolhido][i]) == I.end()){
                I.push_back(sets[set_escolhido][i]);
            }
        }

        custo_final+= custo[set_escolhido];
        sets_resposta.push_back(set_escolhido);

        ordena_crescente(I);

    }

    cout << "Custo final: " << custo_final << "\n";

    for (int i = 0; i < int(sets_resposta.size()); i++){
        cout << sets_resposta[i] << " ";
    }

    cout << "\n";


    return 0;
}