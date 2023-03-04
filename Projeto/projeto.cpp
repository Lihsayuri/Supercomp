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

void ordena_inicio(vector<Filme> &matriz_filmes){
    // Se e somente se o vetor tiver dois horários finais iguais, o que vem primeiro vai ser o vetor com o horśrio inicial menor.

    for (int i = 0; i < int(matriz_filmes.size()); i++){
        if (matriz_filmes[i].fim == matriz_filmes[i+1].fim){
            if (matriz_filmes[i].inicio > matriz_filmes[i+1].inicio){
                Filme aux = matriz_filmes[i];
                matriz_filmes[i] = matriz_filmes[i+1];
                matriz_filmes[i+1] = aux;
            }
        }
    }
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
    ordena_inicio(matriz_filmes);

    // for (int i = 0; i < qtd_filmes; i++){
    //     cout << matriz_filmes[i].inicio << " " << matriz_filmes[i].fim << " " << matriz_filmes[i].categoria << endl;
    // }

    int filmes_vistos = 0;
    vector<Filme> matriz_filmes_vistos;

    for (int i = 0; i < qtd_filmes; i++){
        if (i == 0){
            filmes_vistos++;
            matriz_filmes_vistos.push_back(matriz_filmes[i]);
            filmes_por_categoria[matriz_filmes[i].categoria]--;
        } else{
            int horario_inicial_filme = matriz_filmes[i].inicio;
            int horario_final_filme = matriz_filmes[i].fim;
            int horario_final_assistido = matriz_filmes_vistos[filmes_vistos-1].fim;
            int horario_inicial_assistido = matriz_filmes_vistos[filmes_vistos-1].inicio;
            if (horario_inicial_filme == 0){
                horario_inicial_filme = 24;
            } if (horario_final_filme == 0){
                horario_final_filme = 24;
            }
            if (horario_final_assistido == 0){
                horario_final_assistido = 24;
            } if (horario_inicial_assistido == 0){
                horario_inicial_assistido = 24;
            }
             // // confere se o horário de inicio e fim do filme não estão entre o horário de inicio e fim do filme assistido anteriormente.
            // if ((horario_inicial_filme >= horario_final_assistido) && (horario_final_filme <= horario_final_assistido)){
            //     continue;
            // }

            // organiza os filmes assistidos para que não haja conflitos de horários. Por exemplo: não é possível assistir dois filmes ao mesmo tempo. Além disso, há a restrição de quantidade de filmes por categoria.
            if ((horario_inicial_filme >= horario_final_assistido) && (filmes_por_categoria[matriz_filmes[i].categoria] > 0) && (horario_inicial_filme != horario_inicial_assistido)){   
                filmes_vistos++;
                matriz_filmes_vistos.push_back(matriz_filmes[i]);
                filmes_por_categoria[matriz_filmes[i].categoria]--;
            }
            
        }
    }

    cout << "Foram vistos " << filmes_vistos << " filmes." << endl;

    for (int i = 0; i < int(matriz_filmes_vistos.size()); i++){
        cout << matriz_filmes_vistos[i].inicio << " " << matriz_filmes_vistos[i].fim << " " << matriz_filmes_vistos[i].categoria << endl;
    }


    return filmes_vistos;
}
