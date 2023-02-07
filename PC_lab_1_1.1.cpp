#include <iostream>
#include <omp.h>

void coutHello()
{
	std::cout << "Hello World!" << std::endl;
#pragma omp parallel
	{
		int i = omp_get_thread_num();
		int n = omp_get_num_threads();
		std::cout << "I'm thread " << i << " of " << n << "!\n";
	}
}

void printfHello()
{
	printf("Hello World!\n");
#pragma omp parallel
	{
		int i = omp_get_thread_num();
		int n = omp_get_num_threads();
		printf("I'm thread %d of %d!\n", i, n);
	}
}

int main()
{
	std::cout << "Max threads of the system is " << omp_get_max_threads() << std::endl;

	int count = 0;
	std::cout << "Enter count of threads: ";
	std::cin >> count;

	omp_set_num_threads(count);


	coutHello();
	std::cout << "=========================" << std::endl;
	printfHello();


	system("pause");
	return 0;
}