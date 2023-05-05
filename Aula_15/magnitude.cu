 #include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <chrono>
 #include <cstdlib>
 #include <algorithm>
 #include <cmath>
 #include <random>
 // imports do thrust
  #include <thrust/host_vector.h>
 #include <thrust/device_vector.h>
 #include <thrust/generate.h>
 #include <thrust/functional.h>
 #include <thrust/copy.h> 

 using namespace std::chrono;

 void reportTime(const char* msg, steady_clock::duration span) {
     auto ms = duration_cast<milliseconds>(span);
     std::cout << msg << " - levou - " <<
      ms.count() << " milisegundos" << std::endl;
 }

// CRIAR UM FUNCTOR (TIPO UM KERNEL PARA CALCULAR O QUADRADO)

struct square {
    // não tem parametro interno, então não precisa nem de construtor de copia
    __host__ __device__
    float operator()(const float &x) const { // não é o x vetor, é a coordenada do vetor, só um ponto
        return x * x;
    }
};

 // IMPLEMENTE O CALCULO DA MAGNITUDE COM THRUST
 float magnitude(thrust::device_vector<float> x) {
     thrust::transform(x.begin() , x.end() , x.begin() , square());  // se não colocar nada ou só o begin ele sobrescreve o resultado no próprio vetor   

     float soma_quadrados = thrust::reduce(x.begin(), x.end());
     float result = std::sqrt(soma_quadrados);
     return result;

     // outra solucao:
    //  return std::sqrt(thrust::transform_reduce(x.begin(), x.end(), square(), 0.0f, thrust::plus<float>()));
 }

 int main(int argc, char** argv) {
     if (argc != 2) {
         std::cerr << argv[0] << ": numero invalido de argumentos\n"; 
         std::cerr << "uso: " << argv[0] << "  tamanho do vetor\n"; 
         return 1;
     }
     int n = std::atoi(argv[1]); //numero de elementos
     steady_clock::time_point ts, te;

     // Faça um  vector em thrust 
     
     thrust::host_vector<float> v(n);

     // inicialize o  vector

     ts = steady_clock::now();

     thrust::generate(v.begin(), v.end(), rand);

     thrust::device_vector<float> v_d = v;

     te = steady_clock::now();
     reportTime("Inicializacao", te - ts);

     // Calcule a magnitude do vetor
     ts = steady_clock::now();
     float len = magnitude(v_d);
     te = steady_clock::now();
     reportTime("Tempo para calculo", te - ts);


     std::cout << std::fixed << std::setprecision(4);
     std::cout << "Magnitude : " << len << std::endl;
 }