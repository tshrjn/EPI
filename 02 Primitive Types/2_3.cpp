// 2_3 reversal
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>



long swapBits(long x, int i, int j)
{
	if( ((x >> i) & 1) != ((x >> j) & 1) )
	{
		x ^= ((1LL << i) | (1LL << j));
	}
	return x;
}

long reverseX(unsigned long x, int n)
{
	for (int i = 0, j = n; i < j; ++i, --j)
    	x = swapBits(x, i, j);
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
		
		printf("Reversal: %ld\n", reverseX(x, 63) ); 		
		printf("swap_bits: %ld\n", swapBits(x, i, j) ); 		
 	}

    return 0;
}