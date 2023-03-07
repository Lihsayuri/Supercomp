#include<iostream>
#include<algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <chrono>
#include <vector>
#include <random>
using namespace std;

struct item{
    int peso;
    double valor;
};

// realiza a comparação entre os pesos dos itens para ordenar
bool compareweight(item a, item b) {
  return a.peso < b.peso;
}

int main() {

  //faz o sorteio com base na seed aleatoria (nunca tem a mesma data) 
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);

  int n;
  cin >> n;

  int PESO_MAX;
  cin >> PESO_MAX;
  
  //cria a distribuição binomial para os pesos e valores 
  binomial_distribution<int> distribution_75(1, 0.5);

  vector<item> all_items;
  vector<int> mochila(n, 0);

  for (int i = 0; i < n; i++){
    item mystruct;
    cin >> mystruct.peso;
    cin >> mystruct.valor;

    all_items.push_back(mystruct);
  }

  int peso = 0;
  double valor = 0;

  for (int i = 0; i < n; i++){
    int prob = distribution_75(generator);
    if (prob == 1){
      if (all_items[i].peso + peso <= PESO_MAX){
        peso += all_items[i].peso;
        valor += all_items[i].valor;
        mochila[i] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++){
    int prob = distribution_75(generator);
    if (prob == 1){
      if ((all_items[i].peso + peso <= PESO_MAX) && (mochila[i] == 0)){
        peso += all_items[i].peso;
        valor += all_items[i].valor;
        mochila[i] = 2;
      }
    }
  }  

    cout << peso << " " << valor << endl;
    for (int i = 0; i < n; i++){
      cout << mochila[i] << " ";
    }

}
