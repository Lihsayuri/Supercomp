#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> matriz;

void calcula_distancias(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
    int n = x.size();
    for (int i = 0; i < n; i++) {
        std::vector<double> linha;
        for (int j = 0; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            linha.push_back(sqrt(dx*dx + dy*dy));    
        }
        mat.push_back(linha);
    }
}

void calcula_distancias2(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
    int n = x.size();
    for (int i = 0; i < n; i++) {
        std::vector<double> linha;
        for (int j = 0; j < n; j++) {
            double dist;
            if (i == j){
                dist = 0.0;  // na diagonal principal tem a cidade com ela mesma, logo o resultado vai ser 0
            }
            else if (i < j){   // esse if calcula apenas a parte superior da matriz, pois a parte inferior é simétrica
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                dist = sqrt(dx*dx + dy*dy);
            }
            else {  // caso em que i > j (parte inferior da matriz)
                dist = mat[j][i];
            }

            linha.push_back(dist);    
        }
        mat.push_back(linha);
    }
}


void calcula_distancias3(matriz &mat, std::vector<double> &x, std::vector<double> &y){
    int n = x.size();
    for (int i = 0; i < n ; i++){
        std::vector <double> linha;
        for (int j = 0; j < n; j++){
            linha.push_back(0.0);
        }
        mat.push_back(linha);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double dist = sqrt(dx*dx + dy*dy);
            mat[i][j] = dist;
            mat[j][i] = dist;
        }
    }
}



void calcula_distancias4(matriz &mat, std::vector<double> &x, std::vector<double> &y){
    int n = x.size();
    mat.resize(n*n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double dist = sqrt(dx*dx + dy*dy);
            std::vector<double> vec_dist; 
            vec_dist.push_back(dist);
            mat[i * n + j] = vec_dist;
            mat[j * n + i] = vec_dist;
        }
    }
}


int main() {
    matriz mat;
    std::vector<double> x, y;
    int n;

    std::cin >> n;
    x.reserve(n);
    y.reserve(n);
    for (int i = 0; i < n; i++) {
        double xt, yt;
        std::cin >> xt >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    std::cout << "Versão do 1 \n";
    //calcula_distancias(mat, x, y);

    std::cout << "Versão do 2 \n";
    //calcula_distancias2(mat, x, y);


    std::cout << "Versão do 3 \n";
    //calcula_distancias3(mat, x, y);

    std::cout << "Versão do 4 \n";

    calcula_distancias4(mat, x, y);

    for (auto &linha : mat) {
        for (double el : linha) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;
}


// Formas de analisar o código:
// g++ -Wall -O3 -g euclides-ingenuo.cpp -o euclides-v3
// valgrind --tool=callgrind ./euclides-v3 < t6-in-3.txt
// callgrind_annotate callgrind.out.32779 euclides-ingenuo-v2.cpp 