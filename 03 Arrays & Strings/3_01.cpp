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

template <typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
void reorder(vector<T> &A, int &pivot_index)
{
	T pivot = A[pivot_index];
	/*
	Keep the following invariants during partioning:
	* bottom group: A[0: smaller -1]
	* middle group: A[smaller: equal -1]
	* unclassified group: A[equal: larger]
	* top group: A[larger + 1: A.size() -1]
	*/
	int smaller = 0, equal = 0, larger = A.size() -1;
	while( equal <= larger)
	{
		//A[equal] is the incoming unclassified element
		if (A[equal] < pivot)
			swap(A[smaller++], A[equal++]);
		else if (A[equal] == pivot)
			equal++;
		else
			swap(A[equal], A[larger-- ]);
	}
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
	cout << "Input pivot index: ";
	cin >>t;
	std::cout << "#elements after reordering Array (via Dutch flag partioning):\n";
	reorder(Array,t);
	for (auto i = Array.begin(); i != Array.end(); ++i)
    	std::cout << *i << ' ';
    return 0;

}