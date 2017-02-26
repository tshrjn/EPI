#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
void connect_leaves_helper(shared_ptr<BinaryTree<T> > &n, 
	vector<shared_ptr<BinaryTree<T> > > &L)
{
	if(n)
	{
		if(!n->left && !n->right)
			L.push_back(n);
		else
		{
			connect_leaves_helper(n->left, L);
			connect_leaves_helper(n->right, L);
		}
	}
}

template <typename T>
vector<shared_ptr<BinaryTree<T> > > connect_leaves(shared_ptr<BinaryTree<T> > &n)
{
	vector<shared_ptr<BinaryTree<T> > > L;
	connect_leaves_helper(n, L);
	return L;
}
