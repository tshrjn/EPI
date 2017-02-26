//Binary Search Trees

// My method: maybe wrong
bool isBST(node* head)
{
	if(!head)
		return true;
	if( (head->left ? head->left->key < head->key : true) && (head->right ? head->right->key > head->key: true))
		return isBST(head->right) && isBST(head->left);
	return false;
}

//method 3 on gfg
bool isBST(node* root)
{
	return isBSTUtil(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

bool isBSTUtil(node* &root, int lower, int upper)
{
	if(!root)
		return true;

	if(root->data < lower || root->data > higher)
		return false;

	return isBSTUtil(root->left, lower, root->data) && isBSTUtil(root->right, root->data, upper);
}


//method 4 implementation in EPI
bool isBST(node* n)
{
	int last = numeric_limits<int>::min();
	bool ans = true;

	while(n)
	{
		if(n->left)
		{
			//Find predecssor of n
			node* pre = n->left;
			while(pre->right && pre->right != n)
				pre = pre->right;

			//Build successor link
			if(pre->right) //pre->right == n
			{
				//revert the successor link if predeccsor's successor is n
				pre->right = nullptr;
				if(last > n->data)
					ans = false;
				last = n->data;
				n = n->right;
			}
			else //if predecessor's sucessor is not n
			{
				pre->right = n;
				n = n->left;
			}
		}
		else
		{
			if( last > n->data)
				ans = false;
			last = n->data;
			n=n->right;
		}
	}
	return ans;
}


//method 4: use in order traversal
bool isBST(node* root)
{
	node* prev = NULL;
	//traverse the tree in inorder fasion and keep track of prev node
	if(root)
	{
		if(!isBST(root->left))
			return false;

		//allows only distinct valued nodes
		if(prev != NULL && root->data <=prev->data)
			return false;
		prev = root;

		return isBST(root->right);
	}
	return true;
}

