#include "/Users/tshrjn/stdc++.h"

using namespace std;

//Return (min, max) pair of elements in A
template <typename T>
pair<T,T> find_min_max(vector<T> &A)
{
	if(A.size() <= 1)
		return {A.front(), A.front()};

	//Initialise the min and max pair
	pair<T, T> min_max_pair = minmax(A[0], A[1]);
	for (int i = 2; i < A.size(); i+=2)
	{
		if(i + 1 < A.size())
		{
			pair<T, T> local_pair = minmax(A[i], A[i+1]);
			min_max_pair = {min(min_max_pair.first, local_pair.first),
				max(min_max_pair.second, local_pair.second)};
		}
		else
		{
			min_max_pair = {min(min_max_pair.first, A[i]),
				max(min_max_pair.second, A[i])};
		}
	}
	return min_max_pair;
}