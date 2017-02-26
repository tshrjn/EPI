// 2_11 - Given n , return the primes from 1 to n
/* Things learnt:
1. primes.emplace_back(2);
*/
#include "/Users/tshrjn/stdc++.h"
using std::string;
using std::cin;
using std::vector;

vector<int> generate_primes_from_1_to_n(int n)
{
	int size = std::floor(0.5 * (n - 3)) + 1;
	// is_prime[i] represents (2i + 3) is prime or not
	vector<int > primes;	//store primes from 1 to n
	primes.push_back(2);
	vector<bool> is_prime(size, true);
	for (long i = 0; i < size; ++i)
	{
		if (is_prime[i])
		{
			int p = (i << 1) + 3;
			primes.emplace_back(p);
			//Sieving from p^2, whose index is 2i^2 + 6i +3
			for (long j = ((i * i) << 1) + 6*i + 3; j < size; j += p)
			{
				is_prime[j] = false;
			}
		}
	}
	return primes;
}


int main(int argc, char const *argv[])
{
	int n;
	std::cout << " Input N: ";
	cin >> n;
	vector<int> primes;
	primes = generate_primes_from_1_to_n(n);
	for (auto i = primes.begin(); i != primes.end(); ++i)
    	std::cout << *i << ' ';
    return 0;
}