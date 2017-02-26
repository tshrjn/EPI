#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>	//O(nlogm) Best solution for n << m
vector<T> intersect_arrs2(vector<T> &a, vector<T> &b)
{
	vector<T> intersect;

	for (int i = 0; i < A.size(); ++i)
		if((i == 0 || A[i] != A[i-1]) && binary_search(B.begin(), B.end(), A[i]))
			intersect.emplace_back(A[i]);

	return intersect;
}

template <typename T>	//O(n + m) Best solution for n ~ m
vector<T> intersect_arrs3(vector<T> &a, vector<T> &b)
{
	vector<T> intersect;
	int i = 0, j=0;

	while(i <A.size() && j <B.size())
	{
		if(A[i] == B[j] && (i == 0 || A[i] != A[i-1]))
		{
			intersect.emplace_back(A[i]);
			i++,j++;
		}
		else if( A[i] < B[j])
			++i;
		else
			++j;
	}

	return intersect;
}