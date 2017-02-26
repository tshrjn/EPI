#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
shared_ptr<BinaryTree<T> > reconstruct_pre_in_orders_helper(vector<T> &pre, int &pre_s, int &pre_e,
	vector<T> &in, int &in_s, int &in_e)
{
	shared_ptr<BinaryTree<T> > n = nullptr;

	if(pre_e >pre_s && in_e > in_s)
	{
		auto it = find(in.cbegin() + in_s, in.cbegin() + in_e, pre[pre_s]);
		int left_tree_size = it - (in.cbegin() + in_s);

		return shared_ptr<BinaryTree<T> >(new BinaryTree<T>{
			pre[pre_s],
			//recusively build the left subtree
			reconstruct_pre_in_orders_helper<T>(
				pre, pre_s +1, pre_s +1 +left_tree_size,
				in, in_s, it- in.cbegin()),
			//recursively build the right sub tree
			reconstruct_pre_in_orders_helper<T>(
				pre, pre_s +1 + left_tree_size, pre_e,
				in, it - in.cbegin() +1, in_e)
		});
	}
	return n;
}

template <typename T>
shared_ptr<BinaryTree<T> > reconstruct_post_in_orders(vector<T> &post, vector<T> &in)
{
	return reconstruct_post_in_orders_helper(post, 0, post.size(),
											in, 0, in.size());
}

template <typename T>
shared_ptr<BinaryTree<T> > reconstruct_post_in_orders_helper(vector<T> &post, int &post_s, int &post_e,
	vector<T> &in, int &in_s, int &in_e)
{
	shared_ptr<BinaryTree<T> > n = nullptr;

	if(post_e >post_s && in_e > in_s)
	{
		auto it = find(in.cbegin() + in_s, in.cbegin() + in_e, post[post_e - 1]);
		int left_tree_size = it - (in.cbegin() + in_s);

		return shared_ptr<BinaryTree<T> >(new BinaryTree<T>{
			post[post_e -1],
			//recusively build the left subtree
			reconstruct_post_in_orders_helper<T>(
				post, post_s, post_s +left_tree_size,
				in, in_s, it- in.cbegin()),
			//recursively build the right sub tree
			reconstruct_post_in_orders_helper<T>(
				post, post_s + left_tree_size, post_e -1,
				in, it - in.cbegin() +1, in_e)
		});
	}
	return n;
}

template <typename T>
shared_ptr<BinaryTree<T> > reconstruct_post_in_orders(vector<T> &post, vector<T> &in)
{
	return reconstruct_post_in_orders_helper(post, 0, post.size(),
											in, 0, in.size());
}

