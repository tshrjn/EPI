// 2_1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cmath>
#include <cmath>
#include <sstream>

template <typename T>
void generate_power_set(const std::vector<T> &S)
{
	for (int i = 0; i < (1 << S.size()); ++i) // i < 2^|S|, i.e 2^n
	{
		int x = i;
		while(x)
		{
			int tar = log2(x ^ (x &(x - 1)) );  //log of x afer dropping LSB
			std::cout << S[tar] << ", ";
			if (x &= x - 1)
				std::cout << "\n";
		}
	}
}
int main(int argc, char const *argv[])
{
    // int t = atoi(argv[1]);
 	// if( argc >=2 )
 	// {
		// std::istringstream ss(argv[1]);
		int n,t;
		std::vector<int> set;
		std::cout << "Input #elements in Set: ";
		std::cin >> n;
		std::cout << "Input elements of the Set:\n";
		for (int i = 0; i < n; ++i)
		{
			std::cin >> t;
			set.push_back(t);
		}
		std::cout << "#elements in Power Set: " << std::pow(2, set.size()) << std::endl;
		generate_power_set(set);
		// if (!(ss >> x))
		    // std::cerr << "Invalid number " << argv[1] << '\n';
 	// }

    return 0;
}