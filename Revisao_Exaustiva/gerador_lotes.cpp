#include <chrono>
#include <random>
#include <fstream>
#include <boost/random.hpp>
using std::vector;

using namespace std;

struct Acao{
    string nome;
    int valor_lote;
    int retorno_lote;
    int imposto;
};

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    ofstream inputFile;
    inputFile.open("input.txt");
    inputFile << n << endl;
    vector <Acao> acoes = {{"PETR4", 30000, 2700, 640}, {"DELL6", 60000, 4500, 900}, {"MICR7", 30000, 6400, 1200}, {"IBMC3", 40000, 4600, 940}};

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    // Definindo distribuição normal com média de 3 e desvio padrão de 1
    uniform_int_distribution<int> distribution_distances(0, 3);

    vector<Acao> vetor_acoes;

    for (int i = 0; i < n; i++) {
        Acao acao;
        acao = acoes[distribution_distances(generator)];    
        vetor_acoes.push_back(acao);
    }


    for (int i = 0; i < n; i++){
        inputFile << vetor_acoes[i].nome << " " << vetor_acoes[i].valor_lote << " " << vetor_acoes[i].retorno_lote << " " << vetor_acoes[i].imposto;
        inputFile << "\n";
    }

    inputFile.close();
    return 0;
}

// inputFile << 0 << " ";