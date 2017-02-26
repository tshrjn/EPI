#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
shared_ptr<BinaryTree<T> > find_kth_node_inorder_traversal_binary_tree(shared_ptr<BinaryTree<T> > r, int k)
{
	while(r && k)
	{
		int left_size = r->left ? r->left->size : 0;
		if(left_size < k - 1)
		{
			k -= (left_size +1);
			r = r->right;
		}
		else if(left_size == k -1)
			return r;
		else
		{
			r = r->left;
		}
	}
	throw length_error("no k-th node in given binary tree");

}