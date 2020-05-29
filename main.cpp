
#include <iostream>
#include <chrono>

// Ambitious. But didn't help.
#define unlikely(x)    __builtin_expect(!!(x), 0) 

/**
 * Fibonacci, classic non-tail recursive way
 */
long fib_non_tr(int n) {
	if (unlikely(n < 2)) return n;
	return fib_non_tr(n - 1) + fib_non_tr(n - 2);
}


/**
 * Fibonacci, tail recursive helper with accumulators
 */
long fib_tr_go(int n, long a, long b)
{
	if (unlikely(n == 0)) return a;
	if (unlikely(n == 1)) return b;
	return fib_tr_go(n - 1, b, a + b);
}

/**
 * Fibonacci, tail recursive
 */
long fib_tr(int n)
{
	return fib_tr_go(n, 0, 1);
}

int main(void)
{

	for (int i = 0; i <= 50; ++i) 
	{
		auto start = std::chrono::high_resolution_clock::now();

		long fibNonTr = fib_non_tr(i);

		auto mid = std::chrono::high_resolution_clock::now();

		long fibTr = fib_tr(i);

		auto end = std::chrono::high_resolution_clock::now();

		std::cout << "fib_non_tr(" << i << ") = " << fibNonTr << " (" 
		          << std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count() << " ms)" << std::endl;

		std::cout << "fib_tr(" << i << ")     = " << fibTr << " (" 
          		  << std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count() << " ms)" << std::endl;
	}
	

	return 0;
}