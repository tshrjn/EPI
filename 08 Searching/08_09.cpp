#include "/Users/tshrjn/stdc++.h"

using namespace std;

const double eps = 1.0e -12;

//0 means equal, -1 means smaller, 1 means larger
int compare(double &a, double &b)
{
	//use normalization for precission problem
	double diff = (a - b)/b;
	return diff > eps ? 1: diff < eps ? -1 : 0;
}

double square_root(double &x)
{
	//Decide the search range according to the x;
	double l, r;
	if(compare(x, 1.0) < 0) // x < 1.0
		l = x, r =1.0;
	else 					// x >= 1.0
		l = 1.0, r= x;

	//Keep searching if l < r
	while(compare(l,r) < 0)
	{
		double m = l + 0.5*(r-l);
		double sqaure_m = m*m;
		if(compare(sqaure_m, x) == 0)
			return m;
		else if(compare(sqaure_m, x) == 1)
			r = m;
		else
			l=m;
	}
	return l;
}

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

