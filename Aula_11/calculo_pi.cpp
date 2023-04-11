#include <iostream>
#include <unistd.h>
#include <omp.h>
#include <chrono>

double calcula_pi(int n){
    double soma = 0;
    int multiplicador = -1;
    #pragma omp parallel for num_threads(4) reduction(+ : soma)
    for (int i = 0; i < n; i++){
        //soma+= pow(-1, i)/(2*i + 1);// para que ficar fazendo pow toda hora se é só fazer - par 1 ou - impar -1
        multiplicador *= -1;
        soma+= (double) multiplicador/(2*i + 1);  // fazer isso pra unidade de processamento não utilizar o ponto flutuante

        // ouuuu
        // if (i%2 == 0){
        //     soma+= 1/(2*i + 1);
        // }else{
        //     soma+= -1/(2*i + 1);
        // }

    }

    return soma*4;
}

int main(){
    auto t_start = std::chrono::high_resolution_clock::now();
    long int n = 10000000000;
    double pi = calcula_pi(n);
    std::cout << "Pi = " << pi << std::endl;

    int nthreads = omp_get_max_threads(); // vê todas as que tem disponíveis 
    std::cout << "Número de threads: " <<  nthreads << std::endl;

    auto t_end = std::chrono::high_resolution_clock::now();

    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    double elapsed_time_s = elapsed_time_ms/1000;
    std::cout << "Tempo de execução: " << elapsed_time_s << " s" << std::endl;


    return 0;
}