// 2_1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>

long swap_bits(unsigned long x, int i, int j)
{
	if( ((x >> i) & 1) != ((x >> j) & 1) )
	{
		x ^= ((1LL << i) | (1LL << j));
	}
	return x;
}

long reversal(unsigned long x)
{
	unsigned long y = 0;
	while(x)
	{
		y <<= 1;
		y |= (x & !(x - 1));
		printf("LSBs of x: %ld\n", (x & !(x - 1)) );
		printf("y: %ld\n", y);
		printf("x: %ld\n", x);
		x >>= 1;
		
	}
	return y;
}

int main(int argc, char const *argv[])
{
    // int t = argv[1];
 	if( argc >=2 )
 	{
		std::istringstream ss(argv[1]);
		int x, i, j;
		if (!(ss >> x))
		    std::cerr << "Invalid number " << argv[1] << '\n';
		std::cout << "Input i & j:\n";
		std::cin >>i;
		std::cin >>j;
		
		printf("Reversal: %ld\n", reversal(x) ); 		
		printf("swap_bits: %ld\n", swap_bits(x, i, j) ); 		
 	}

    return 0;
}