#include "/Users/tshrjn/stdc++.h"
using namespace std;

bool is_valid_Sudoku(std::vector< std::vector<int> > &A)
{
	//Check rows
	for (int i = 0; i < A.size(); ++i)
	{
		std::vector<int> is_present(A.size() + 1, false);
		for (int j = 0; j < A.size(); ++j)
		{
			if(A[i][j] != 0 && is_present[A[i][j]] == true)
				return false;
			else
				A[i][j]=true;
		}
	}

	//Check cols
	for (int i = 0; i < A.size(); ++i)
	{
		std::vector<int> is_present(A.size() + 1, false);
		for (int j = 0; j < A.size(); ++j)
		{
			if(A[j][i] != 0 && is_present[A[j][i]] == true)
				return false;
			else
				A[j][i]=true;
		}
	}

	// Check squares
	int small_square = sqrt(A.size());
	for (int I = 0; I < small_square; ++I)
	{
		for (int J = 0; J < small_square; ++J)
		{
			vector<bool> is_present(A.size() + 1, false);
			for (int i = 0; i < small_square; ++i)
			{
				for (int j = 0; j < small_square; ++j)
				{
					if( A[small_square*I + i][small_square*J+ j] != 0
						&& is_present[A[small_square*I + i][small_square*J+ j]])
						return false;
					else
						is_present[A[small_square*I + i][small_square*J+ j]] = true;
				}
			}
		}
	}
}