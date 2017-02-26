// 3_01 - Given Array A & index i, return
/* Things learnt:
1. primes.emplace_back(2);
*/
#include "/Users/tshrjn/stdc++.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <typename T> //T is heightType
T find_battery_capacity(vector<T> &z)
{
	T minHeight = std::numeric_limits<T>::max(), capacity = 0;
	for (const T &height : z)
	{
		capacity = std::max(capacity, height - minHeight);
		minHeight = std::min(minHeight, height);
	}
	return capacity;
}

int main(int argc, char const *argv[])
{
	int n,t;
	std::vector<int> Array;
	std::cout << "Input #elements in Array: ";
	std::cin >> n;
	std::cout << "Input elements of the Array:\n";
	for (int i = 0; i < n; ++i)
	{
		std::cin >> t;
		Array.push_back(t);
	}
	std::cout << " Required capacity: " << find_battery_capacity(Array) << endl;
    return 0;
}