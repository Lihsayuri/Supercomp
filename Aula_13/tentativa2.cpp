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
    int N = 100000;

    // faça um gerador de numeros aleatorios que vai de 0 a 1


    #pragma omp parallel num_threads(4) 
    {
        double sum_local = 0;
        int num_threads = omp_get_num_threads();
        int tid = omp_get_thread_num();
        int chunk_size = N/num_threads;
        for (int i = 0; i < chunk_size; i++){
            std::default_random_engine generator(((tid+1.0)/num_threads)*100);
            std::uniform_real_distribution<double> distribution(0.0, 1.0);

            double x = (double) distribution(generator);
            double y = (double) distribution(generator);
            if (x*x + y*y <= 1){
                // cout << "Thread " << tid << " gerou o numero " << ((tid+1.0)/(double)N)<< endl;
                sum_local += 1.0;
            }
        }

        // atualizar a soma global
        #pragma omp critical
        pi_estimate += sum_local;

    }


    cout << "AQUIII " << std::setprecision(6) << 4.0 * pi_estimate / N << endl;


    auto t_end = std::chrono::high_resolution_clock::now();

    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    double elapsed_time_s = elapsed_time_ms/1000;
    std::cout << "Tempo de execução mudei: " << elapsed_time_s << " s" << std::endl;

    return 0;
}
