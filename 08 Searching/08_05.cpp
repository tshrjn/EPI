#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
int search_smallest(vector<T> &A)
{
	int l = 0, r= A.size() -1, res = -1;
	while(l < r)
	{
		int m = l + ((r-l) / 2);
		if(A[m] > A[r])
			// Minimum must be in [mid + 1 : right].
			l = m +1;
		else //A[m] < A[r]
			// Minimum cannot be in [mid + 1 : right] so it must be in [left : mid].
			r = m;
	}

	//loop ends when left == right
	return l;
}

//For the case of repition of elements:
template <typename T>
int search_smallest_helper(vector<T>  &A, int &l, int &r)
{
	if(l == r)
		return l;
	int m = l + ((l-r)/2);

	if(A[m] > A[r])
		return  search_smallest_helper(A,m +1, r);
	else if(A[m] < A[r])
		return search_smallest_helper(A, l, m)
	else{ //A[m] == A[r]
		//smallest element must exist either on the left or the right side
		int l_res = search_smallest_helper(A, l, m);
		int r_res = search_smallest_helper(A, m +1, r);
		return A[r_res] < A[l_res] ? r_res : l_res;
	}
}

template <typename T>
int search_smallest_4repition(vector<T> &A)
{
	return search_smallest_helper(A, 0, A.size() -1);
}