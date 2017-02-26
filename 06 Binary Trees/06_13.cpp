#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
int get_depth(shared_ptr<BinaryTree<T> > n)
{
	int d = 0;
	while(n)
	{
		d++, n = n->parent;
	}
	return d;
}

template <typename T>
shared_ptr<BinaryTree<T> > LCA(shared_ptr<BinaryTree<T> > a, shared_ptr<BinaryTree<T> > b)
{
	int da = get_depth(a), db =get_depth(b);
	if(db > da)
		swap(a,b);

	//Advance deeper node first
	int depth_diff = da - db;
	while(depth_diff--)
		a = a->parent;

	//both pointers advance until they found a common ansector
	while(a != b)
		a = a->parent, b = b->parent;

	return a;
}
