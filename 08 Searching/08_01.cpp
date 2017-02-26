//Binary Search First K
#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
int search_first(vector<T> &A, T &k)
{	//binary seacrh as we get a sorted Array
	int l = 0, r= A.size() -1, res = -1;
	while(l <= r)
	{
		int m = l + ((r-l) / 2);
		if(A[m] > k)
			r = m -1;
		else if(A[m] == k)
			res = m, r = m-1;//record solution & keep searching the left part
		else //A[m] < k
			l = m+1;
	}
	return res;
}