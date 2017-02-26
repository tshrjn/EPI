// 2_1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>

int parity1(unsigned long x)
{
	int result = 0;
	while(x)
	{
		result ^= (x & 1);
		x >>= 1;
	}
	return result;
}

int parity2(unsigned long x)
{
	int result = 0;
	while(x)
	{
		result ^= 1;
		x &= (x-1);
	}
	return result;
}

int main(int argc, char const *argv[])
{
    // int t = argv[1];
 	if( argc >=2 )
 	{
		std::istringstream ss(argv[1]);
		int x;
		if (!(ss >> x))
		    std::cerr << "Invalid number " << argv[1] << '\n';
		// std::cin >>t;
		
		// printf("Parity1: %d\n", parity1(x) ); 		
		printf("Parity2: %d\n", parity2(x) ); 		
 	}

    return 0;
}