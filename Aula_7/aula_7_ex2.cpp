#include<iostream>
#include<algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <chrono>
#include <vector>
#include <random>
using namespace std;

struct item{
    int id;
    int peso;
    double valor;
};

// bool ord (item i, item j){
//   return (i.peso<j.peso);
// }

vector<item> knapsack(vector <item> items, int tries){
  int n = items.size();
  vector<item> mochila;
  vector<item> melhor;
  mochila.reserve(n);
  melhor.reserve(n);
  double max = 0;

  for (int t = 0; t < tries; t++){
    for (int i = 0; i < n; i++){
      if ((rand()%2 == 1) && (items[i].peso <= W)){
        mochila[i] = items[i];
        W -= items[i].peso;
      } else {
        mochila[i].id = -1;
      }
    }

    double valor = 0;
    for (int i = 0; i < n; i++){
      if (mochila[i].id != -1){
        valor += mochila[i].valor;
      }
    }

    if (valor > max){
      melhor = mochila;
      max = valor;
    }
  }

  return melhor, max;

}

int main() {
  int n, W;
  cin >> n >> W;
  vector<item> items;
  vector<item> melhor;
  int max = 0;
  items.reserve(n);

  for (int i = 0; i < n; i++){
    double peso, valor;
    cin >> peso >> valor;
    items.push_back({i, peso, valor});
  }

  melhor, max = knapsack(items, 100);


  for (int i = 0; i < n; i++){
    cout << melhor[i].id << " ";
  }
  cout << endl;

  return 0;

}
