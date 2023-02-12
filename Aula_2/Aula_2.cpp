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

int distancias(){
    int n;
    cin >> n;
    cout << "Número de linhas: " << n << "\n";
    vector<vector<double> > vec;

    for (int i = 0; i < n; i++){
        vector<double> linha;
        for (int j = 0; j < 2; j++){
            double num;
            cin >> num;
            linha.push_back(num);
        }
        vec.push_back(linha);
        // cout << "Linha0: " << linha[0] << "\n";
        // cout << "Linha1: " << linha[1] << "\n";
        
    }

    vector <double> resultados;
    for (int i = 1; i < n; i++){
            int x1 = pow((vec[i][0] - vec[i-1][0]), 2);
            int y1 = pow((vec[i][1] - vec[i-1][1]), 2);
            double distancia = sqrt(x1 + y1);
            resultados.push_back(distancia);
            cout << "distancia: " << distancia << "\n";        
            
    }


    return 0;
}

int main(){
    // exemplo1();
    // somatorio(10);
    // exemplo2();
    // media_variancia();
    distancias();
    return 0;
}