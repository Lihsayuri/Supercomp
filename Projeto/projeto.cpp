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

struct Filme{
    int inicio;
    int fim;
    int categoria;
};


void ordena_final(vector<Filme> &matriz_filmes){
    std::sort(matriz_filmes.begin(), matriz_filmes.end(), [] (Filme &a, Filme &b){
		return a.fim < b.fim;
	});

}


int main(){
    int qtd_filmes, qtd_categorias;
    cin >> qtd_filmes >> qtd_categorias;

    vector<int> filmes_por_categoria(qtd_categorias, 0);
    vector<Filme> matriz_filmes;

    for (int i = 0; i < qtd_categorias; i++){
        cin >> filmes_por_categoria[i];
    }


    for (int i = 0; i < qtd_filmes; i++){
        Filme filme;
        cin >> filme.inicio >> filme.fim >> filme.categoria;
        matriz_filmes.push_back(filme);
    }

    ordena_final(matriz_filmes);

    // Se o vetor tiver dois horários finais iguais, o que vem primeiro vai ser o vetor com o horśrio inicial menor.


    for (int i = 0; i < qtd_filmes; i++){
        cout << matriz_filmes[i].inicio << " " << matriz_filmes[i].fim << " " << matriz_filmes[i].categoria << endl;
    }

    return 0;
}