#include <vector>
#include <iostream>
#include <unistd.h>
#include <omp.h>


double conta_complexa(int i) {
	return 2 * i;
}

int main() {
	int N = 10000; 
	std::vector<double> vec (N, 0);
	#pragma omp parallel for default(none) shared(vec) firstprivate(N) //Para corrigir isso, é possível usar a cláusula firstprivate(N) no pragma parallel, o que irá definir N como uma variável privada e copiá-la para cada thread. 
	for (int i = 0; i < N; i++) {
		#pragma omp critical
		{
		vec[i] = conta_complexa(i);
		}
	}
		
	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << " ";
		// std::cout << i << " ";
	}
	
	return 0;
}


// Ao usar a cláusula default(none), o compilador OpenMP exige que todas as variáveis ​​sejam especificadas explicitamente como
//  compartilhadas ou privadas usando as cláusulas shared ou private, respectivamente. Isso ajuda a tornar o código mais seguro e menos
//   suscetível a bugs de concorrência.