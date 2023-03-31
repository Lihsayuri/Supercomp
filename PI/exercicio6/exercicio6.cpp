#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <random>
#include <chrono>
#include <stdlib.h> 
#include <random>
#include <chrono>
#include <fstream>
#include <bitset>
#include <map>
#include <ctime>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::bitset;
using std::map;
using std::min;
using std::max;

struct Filme{
    int inicio;
    int fim;
    int categoria;
};

void ordena_final(vector<Filme> &vetor_filmes){
    std::sort(vetor_filmes.begin(), vetor_filmes.end(), [] (Filme &a, Filme &b){
		return a.fim < b.fim;
	});

}


// n é a qtd_filmes e m é o número de categorias

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> max_filmes(m+1, 0);


    for (int i = 1; i < m+1; i++){
        cin >> max_filmes[i];
    }

    Filme filme_vazio = {0, 0, 0};
    vector<Filme> vetor_filmes (n+1, filme_vazio);

    for (int i = 1; i < n+1; i++){
        Filme filme;
        cin >> filme.inicio >> filme.fim >> filme.categoria;
        vetor_filmes[i] = filme;
    }


    ordena_final(vetor_filmes);

    // Cria uma matriz dp[N+1][M+1] preenchida com zeros
    vector<int> interno(m+1, 0);
    vector<vector<int>> dp(n+1, interno);

    for (int j = 1; j < m+1; j++){
        dp[0][j] = max_filmes[j];
    }


    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++){
            if (vetor_filmes[i].categoria != j){
                dp[i][j] = dp[i-1][j];
            } else{
                int last = i - 1;
                while((last >= 0) && (vetor_filmes[last].fim > vetor_filmes[i].inicio)){ //enquanto  existe anterior e se o final do filme anterior é maior que o início do atual
                    last = last - 1;
                }
                int max_count = 0;
                for (int k = 0; k < min(dp[last][j-1], (vetor_filmes[i].fim - vetor_filmes[i].inicio - 1)); k++){
                    max_count = max(max_count, dp[last][j-1-k] + k + 1);
                }
                dp[i][j] = max(dp[i-1][j], max_count);
            }
        }
    }

    for (int i = 0; i < n+1; i++){
        for (int j = 1; j < m+1; j++){  // estou começando com j=1 porque simplesmente pulamos ele. Consideramos o i = 0 com as categorias dos filmes, mas o j = 0 não tem nada
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
