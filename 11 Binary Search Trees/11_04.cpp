//Binary Search Trees

//recursive
node* find_first_equal_k(node* root, int k)
{
	if(!root)
		return nullptr;

	if(root->data == k)
	{
		node* left = find_first_equal_k(root->left, k);
		if(!left)
			return left;
	}
	return find_first_equal_k(root->data > k ? root->left: root->right , k);
}

//iterative
node* find_first_equal_k(node* root, int k)
{
	while(root)
	{
		if(root->data < k)
			root=root->right;
		else if( root->data > k)
			root = root->left;
		else
		{
			node* l = root->left;
			while(l)
			{
				if(l->data != k)
					break;
				else
				{
					root = l;
					l = l->left;
				}
			}
			return r;
		}
	}
	return nullptr;
}