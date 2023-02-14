#include <iostream>

int hello_world(){
    std::cout <<"Hello World! YAYYY \n";
    return 0;
}


// -------------------------------------------------------------------------------------------------------------------

//                                        ENTRADA E SAÍDA EM C++ 
// --------------------------------------------------------------------------------------------------------------------


// Em C usamos as funções printf para mostrar dados no terminal e scanf para ler dados. Em C++ essas funções também podem ser usadas, mas em geral
// são substituídas pelos objetos std::cin e std::cout (disponíveis no cabeçalho iostream).
// A maior vantagem de usar cin e cout é que não precisamos mais daquelas strings de formatação estranhas com %d, %s e afins. Podemos passar 
// variáveis diretamente para a saída do terminal usando o operador <<. Veja um exemplo abaixo.

int exemplo1(){
    int a = 10;
    double b = 3.2;
    std::cout << "Saída: " << a << ";" << b << "\n";
    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------

// A implementação de algoritmos definidos usando expressões matemáticas é uma habilidade importante neste curso.
// Escreva um programa que receba um inteiro n e calcule a seguinte série.
// Mostre as primeiras 15 casas decimais de S. Veja a documentação de std::setprecision aqui.   [1/2^i]

#include <iostream>
#include <cmath>
#include <iomanip> 

int somatorio(int n){
    //double soma = 0;
    double soma = 1;
    int p = 1;
    for (int i = 1; i < n; i++) {
    //for (int i = 0; i < n; i++) {
      //soma += 1/pow(2, i);
      soma += 1.0/(p=p<<1);
      //soma += 1.0/(1<<i);
    }
    std::cout << std::setprecision(16) << "Soma: " << soma ;
    return 0;
}


//---------------------------------------------------------------------------------------------------------------------

//                                   VETORES EM C++
// --------------------------------------------------------------------------------------------------------------------

// A estrutura std::vector é um vetor dinâmico que tem funcionalidades parecidas com a lista de Python ou o ArrayList de Java. O código abaixo
//  exemplifica seu uso e mostra algumas de suas funções. Note que omitimos o uso de std no código abaixo.


#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int exemplo2(){
    int n;
    cin >> n;
    vector<double> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(i * i);
    }

    cout << "Tamanho do vetor: " << vec.size() << "\n";
    cout << "Primeiro elemento: " << vec.front() << "\n";
    cout << "Último elemento: " << vec.back() << "\n";
    cout << "Elemento 3: " << vec[2] << "\n";

    return 0;
}

// Crie um programa que lê um número inteiro n e depois lê n números fracionários xi
// . Faça os seguintes cálculos e motre-os no terminal com 10 casas decimais.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int media_variancia(){
    int n;
    std::cin >> n;
    std::vector<double> vec;

    for (int i = 0; i < n; i++) {    
        double num ;
        std::cin >> num;
        vec.push_back(num);
    }

    double soma = 0;
    for (int j = 0; j < n ; j++) {
      soma += vec[j];
    }

    double media = soma/n;

    double soma2 = 0;
    for (int k = 0; k < n ; k++) {
      soma2 += pow(vec[k] - media, 2);
    }

    double variancia = soma2/n;

    cout << "Tamanho do vetor: " << vec.size() << "\n";
    cout << "Primeiro elemento: " << vec.front() << "\n";
    cout << "Último elemento: " << vec.back() << "\n";
    cout << setprecision(2) << "Média: " << media << "\n";
    cout << setprecision(2) << "Variância: " << variancia << "\n";
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------

//                                        Matrizes (versão 1)
// --------------------------------------------------------------------------------------------------------------------

int calcula_distancias(){
    int n;
    cin >> n;
    vector<double> x,y;
    // cout << "Número de linhas: " << n << "\n";
    vector<vector<double> > vec;

    for (int i = 0; i < n; i++){
        double xa, ya;
        cin >> xa >> ya;
        x.push_back(xa);
        y.push_back(ya);        
    }

    vector<vector<double>> resultados;

    for (int i = 0; i < n ; i++){
        vector <double> linha;
        for (int j = 0; j < n; j++){
            linha.push_back(0.0);
        }
        resultados.push_back(linha);
    }



    for (int i = 0; i < n; i++){
        vector<double> linha;
        for (int j = 0; j < n; j++){
            if (i == j){
                resultados[i][j] = 0.0;  // na diagonal principal tem a cidade com ela mesma, logo o resultado vai ser 0
                continue;
            }
            else if (i < j){   // esse if calcula apenas a parte superior da matriz, pois a parte inferior é simétrica
                double x1 = pow((x[i] - x[j]), 2);
                double y1 = pow((y[i] - y[j]), 2);
                double distancia = sqrt(x1 + y1);
                resultados[i][j] = distancia;
            }
            else {  // caso em que i > j (parte inferior da matriz)
                resultados[i][j] = resultados[j][i];
            }

        }
    }

    // for apenas para mostrar a matriz
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << resultados[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}



int calcula_distancias2(){
    int n;
    cin >> n;
    vector<double> x,y;
    // cout << "Número de linhas: " << n << "\n";
    vector<vector<double> > vec;

    for (int i = 0; i < n; i++){
        double xa, ya;
        cin >> xa >> ya;
        x.push_back(xa);
        y.push_back(ya);        
    }

    vector<vector<double>> resultados;

    for (int i = 0; i < n; i++){
        vector<double> linha;
        for (int j = 0; j < n; j++){
            double dist;
            if (i == j){
                dist = 0.0;  // na diagonal principal tem a cidade com ela mesma, logo o resultado vai ser 0
            }
            else if (i < j){   // esse if calcula apenas a parte superior da matriz, pois a parte inferior é simétrica
                double x1 = pow((x[i] - x[j]), 2);
                double y1 = pow((y[i] - y[j]), 2);
                dist = sqrt(x1 + y1);
            }
            else {  // caso em que i > j (parte inferior da matriz)
                dist = resultados[j][i];
            }

            linha.push_back(dist);
        }

        resultados.push_back(linha);
    }

    // for apenas para mostrar a matriz
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << resultados[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}




int main(){
    // exemplo1();
    // somatorio(10);
    // exemplo2();
    // media_variancia();
  
    //calcula_distancias(); 
    calcula_distancias2(); 


    return 0;
}