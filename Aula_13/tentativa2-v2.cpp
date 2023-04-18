#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;


int main(){
    auto t_start = std::chrono::high_resolution_clock::now();
    double pi_estimate = 0.0;
    long int N = 100000;

    // faça um gerador de numeros aleatorios que vai de 0 a 1


    #pragma omp parallel for num_threads(4) reduction(+ : pi_estimate) 
    for (int i = 0; i < N; i++){
        int num_threads = omp_get_num_threads();
        int tid = omp_get_thread_num();

        std::default_random_engine generator(tid*rand());
        std::normal_distribution<double> distribution(0.0, 0.5);        

        double x = (double) distribution(generator);
        double y = (double) distribution(generator);

        // cout << "x: " << x << " y: " << y << endl;

        if (x*x + y*y <= 1){
            pi_estimate += 1.0;
        }
    }
    

    cout << pi_estimate << endl;

    cout << "PI " << std::setprecision(6.4) << 4.0 * pi_estimate / (double) N << endl;


    auto t_end = std::chrono::high_resolution_clock::now();

    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    double elapsed_time_s = elapsed_time_ms/1000;
    std::cout << "Tempo de execução mudei: " << elapsed_time_s << " s" << std::endl;

    return 0;
}
