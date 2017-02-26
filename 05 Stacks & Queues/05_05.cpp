#include "/Users/tshrjn/stdc++.h"

using namespace std;
void transfer(int &n, array<stack<int>, 3> &pegs, int &from, int &to, int &use)
{
	if(n>0)
	{
		transfer(n - 1, pegs, from, use, to);
		pegs[to].push(pegs[from].top());
		pegs[from].pop();
		cout << "Move from peg " << from << "to peg "<< to<<endl;
		transfer(n -1, pegs, use, to, from);
	}
}

void move_transfer_hanoi(int &n)
{
	array<stack<int>, 3> pegs;
	//initialise pegs
	for (int i = n; i >= 1 ; --i)
	{
		pegs[0].push(i);
	}
	transfer(n, pegs, 0, 1, 2);
}