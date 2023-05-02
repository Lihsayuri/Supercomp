#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/sort.h>
#include <thrust/copy.h>
#include <thrust/random.h>
#include <vector>
using namespace std;

int main() {
  thrust::device_vector<double> d_vec(10);
  thrust::sequence (d_vec.begin(), d_vec.end(), 0.0f, 1.0f);

  thrust::device_vector<double>::iterator begin = d_vec.begin();
  thrust::device_vector<double>::iterator end = d_vec.end();
  int len = end - begin;


  double media = thrust::reduce(d_vec.begin(), d_vec.end()) / len;

//   thrust::device_vector<double> media_vector(len, media);

  thrust::constant_iterator<double> media_vector_begin(media);
  thrust::constant_iterator<double> media_vector_end = media_vector_begin + len;

  thrust::device_vector<double> subtracao_vec(len);
  thrust::device_vector<double> quadrado_vec(len);
  thrust::transform (d_vec.begin(), d_vec.end(), media_vector_begin, subtracao_vec.begin(), thrust::minus<double>());
  thrust::transform (subtracao_vec.begin(), subtracao_vec.end(), subtracao_vec.begin(), quadrado_vec.begin(), thrust::multiplies<double>());

  double soma_quadrados = thrust::reduce(quadrado_vec.begin(), quadrado_vec.end());

  double variance = soma_quadrados / len;

  std::cout << "variancia: " << variance << std::endl;
}

// nvcc -arch=sm_70  aula.cu -o aula_14