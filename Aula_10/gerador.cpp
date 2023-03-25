#include <chrono>
#include <random>
#include <fstream>
#include <boost/random.hpp>

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
    uniform_int_distribution<int> distribution_weight(1, 40);
    uniform_int_distribution<int> distribution_value(1, 200);

    for (int i = 0; i < n; i++) {
        int weight = distribution_weight(generator);
        int value = distribution_value(generator);

        inputFile << weight << " " << value << endl;
    }

    inputFile.close();
    return 0;
}