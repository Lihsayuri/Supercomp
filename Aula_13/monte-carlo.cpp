#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <chrono>
#include <random>
using namespace std;


int main(){

    auto t_start = std::chrono::high_resolution_clock::now();
    double sum = 0;
    int N = 100000;

    // faça um gerador de numeros aleatorios que vai de 0 a 1 com o uniform_int_distribution

    std::default_random_engine generator(42);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < N; i++){
        // sorteie pontos x,y∈[0,1]
        double x = (double) distribution(generator);
        double y = (double) distribution(generator);
        if (x*x + y*y <= 1){
            sum += 1;
        }
    }
    cout << 4 * sum / N << endl;

    auto t_end = std::chrono::high_resolution_clock::now();

    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    double elapsed_time_s = elapsed_time_ms/1000;
    std::cout << "Tempo de execução: " << elapsed_time_s << " s" << std::endl;

    return 4 * sum / N;

}
