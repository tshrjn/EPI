#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
void print_BST_in_sorted_order(shared_ptr<BinarySearchTree<T> > &n){
	stack<shared_ptr<BinarySearchTree<T> > > s;
	shared_ptr<BinarySearchTree<T> > curr = n;

	while(!s.empty() || curr)
	{
		if(curr)
		{
			s.push(curr);
			cur = curr->left;
		}
		else
		{
			curr = s.top();
			s.pop();
			cout << curr->data << endl;
			curr = curr->right;
		}
	}
}