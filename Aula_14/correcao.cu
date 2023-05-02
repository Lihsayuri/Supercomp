#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/sort.h>
#include <thrust/copy.h>
#include <thrust/random.h>
#include <vector>
using namespace std;

int main() {
  int N = 10;
  thrust::device_vector<float> x(N);
  thrust::sequence (x.begin(), x.end());

  //PASSO 1
  float media = thrust::reduce(x.begin(), x.end()) / x.size();

  //PASSO 2 (x -mu)
  thrust::device_vector<float> mu(N, media);
  thrust::transform(x.begin(), x.end(), mu.begin(), x.begin(), thrust::minus<float>());

  // PASSO 3 (x - mu)^2
  thrust::transform(x.begin(), x.end(), x.begin(), thrust::square<float>());

  // PASSO 4  SUM (x - mu)^2/ N
  float variance = thrust::reduce(x.begin(), x.end()) / N;

  std::cout << "variancia: " << variance << std::endl;
}

// nvcc -arch=sm_70  correcao.cu -o correcao