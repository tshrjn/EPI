#include "/User/tshrjn/stdc++.h"

using namespace std;

template <typename T>
void print_binary_tree_in_level_order(shared_ptr<BinaryTree<T> > &n)
{
	//Prevent empty tree
	if(!n)
		return;

	queue<shared_ptr<BinaryTree<T> > > q;
	q.emplace(n);
	int count = q.size();
	while(!q.empty())
	{
		shared_ptr<BinaryTree<T> > curr = q.front();
		cout << curr->data << " ";
		if(curr->left)
			q.emplace(curr->left);
		if(curr->right)
			q.emplace(curr->right);
		q.pop();
		if(--count == 0)
		{
			cout << endl;
			count = q.size();
		}
	} 
}