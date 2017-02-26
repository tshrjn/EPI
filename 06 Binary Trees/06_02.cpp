#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
pair<shared_ptr<BinaryTree<T> >, int> find_non_k_balanced_node_helper(shared_ptr<BinaryTree<T> > &n, int &k){
	//empty tree
	if(!n)
		return {nullptr, 0};

	//early return if left subtrree is not k-balanced
	auto L = find_non_k_balanced_node_helper<T>(n->left, k);
	if(L.first)
		return L;
	//early return if right subtrree is not k-balanced
	auto R = find_non_k_balanced_node_helper<T>(n->right, k);
	if(R.first)
		return R;

	int node_num = L.second + R.second + 1; //#nodes in n
	if(abs(L.second - R.second) > k)
		return{n , node_num};

	return {nullptr, node_num}; 
}

template <typename T>
shared_ptr<BinaryTree<T> > find_non_k_balanced_node( shared_ptr<BinaryTree<T> > &n, int &k)
{
	return find_non_k_balanced_node_helper<T>(n,k).first;
}