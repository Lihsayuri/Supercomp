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
            linha.push_back((dx*dx + dy*dy));    
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
                dist = (dx*dx + dy*dy);
            }
            else {  // caso em que i > j (parte inferior da matriz)
                dist = mat[j][i];
            }

            linha.push_back(dist);    
        }
        mat.push_back(linha);
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

    calcula_distancias(mat, x, y);

    calcula_distancias2(mat, x, y);
    

    for (auto &linha : mat) {
        for (double el : linha) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
