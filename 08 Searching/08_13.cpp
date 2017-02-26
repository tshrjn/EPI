#include "/Users/tshrjn/stdc++.h"

using namespace std;

//Partition A according to pivot, return its index after partition
template <typename T>
int partition(vector<T> &A, int &l, int &r, int &pivot)
{
	T pivot_value = A[pivot];
	int larger_index = l;

	swap(A[pivot], A[r]);
	for (int i = l; i < r; ++i)
	{
		if(A[i] > pivot_value)
			swap(A[i], A[larger_index++]);
	}

	swap(A[r], A[larger_index]);
	return larger_index;
}

template <typename T>
T find_kth_largest(vector<T> A, int &k)
{
	int l=0, r=A.size() -1;
	while(l <=r)
	{
		default_random_engine gen((random_device())());
		uniform_int_distribution<int> dis(l, r); // generate random int in [l,r]
		int p = partition(A, l, r, dis(gen));
		if( p == k -1)
			return A[p];
		else if(p > k - 1)
			r = p -1;
		else // p <k -1
			l = p +1;
	}
}