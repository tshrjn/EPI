#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
shared_ptr<BinaryTree<T> > reconstruct_preorder(vector<T> &preorder)
{
	stack<shared_ptr<BinaryTree<T> > > s;

	for (auto it = preorder.crbegin(); it != preorder.crend() ; ++it)
	{
		if (!(*it))
			s.emplace(nullptr);
		else // non-null
		{
			shared_ptr<BinaryTree<T> > l = s.top();
			s.pop();
			shared_ptr<BinaryTree<T> > r = s.top();
			s.pop();
			s.emplace(new BinaryTree<T>{*(*it), l, r})
		}
	}
	return s.top();
}
