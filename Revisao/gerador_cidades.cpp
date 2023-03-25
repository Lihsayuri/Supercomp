#include <chrono>
#include <random>
#include <fstream>
#include <boost/random.hpp>
using std::vector;

using namespace std;

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int max_size = atoi(argv[2]);

    ofstream inputFile;
    inputFile.open("input.txt");
    inputFile << n << " " << max_size << endl;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    // Definindo distribuição normal com média de 3 e desvio padrão de 1
    uniform_int_distribution<int> distribution_distances(1, 40);

    vector<int> cidade(n, 0);
    vector<vector<int>> distancias_cidades(n, cidade);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int distance = distribution_distances(generator);
            if (i == j){
                distancias_cidades[i][j] = 0;
            } else if (i < j){
                distancias_cidades[i][j] = distance;
            } else {
                distancias_cidades[i][j] = distancias_cidades[j][i];
            }
        }

    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            inputFile << distancias_cidades[i][j] << " ";
        }
        inputFile << "\n";
    }

    inputFile.close();
    return 0;
}

// inputFile << 0 << " ";