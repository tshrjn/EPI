#include "/Users/tshrjn/stdc++.h"

using namespace std;

int search_index_value_equal(vector<int> &A)
{
	int l = 0, r= A.size() -1, res = -1;
	while(l <= r)
	{
		int m = l + ((r-l) / 2);
		if(A[m] > m)
			r = m -1;
		else if(A[m] == m)
			res = m, r = m-1; //record solution & keep searching the left part
		else //A[m] <= k
			l = m+1;
	}
	return res;
}