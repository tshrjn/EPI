#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
shared_ptr<BinaryTree<T> > LCA(shared_ptr<BinaryTree<T> > a, shared_ptr<BinaryTree<T> > b)
{
	unordered_set<shared_ptr<BinaryTree<T> > > hash;

	while(a || b)
	{
		if (a)
		{
			if(hash.emplace(a).second == false)
				return a; // adds a failed because a exists in hash
			a = a->parent;
		}
		if (b)
		{
			if(hash.emplace(b).second == false)
				return b; // adds b failed because b exists in hash
			b = b->parent;
		}
	}
	
	//throw error if a & b are not in the same tree
	throw invalid_argument("a & b are not in the same tree");
}
