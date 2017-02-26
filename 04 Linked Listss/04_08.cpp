#include "/Users/tshrjn/stdc++.h"

//2 pointers traversal: have a prev to remove curr

template <typename T>
void remove_kth_last(shared_ptr<node_t<T> > & L, int &k)
{
	//Advance k steps first
	shared_ptr<node_t<T> > ahead = L;
	int num = k;
	while(ahead && num--)
		ahead = ahead->next;

	if(num)
		cout << "LL is not long enough";

	shared_ptr<node_t<T> >pre = nullptr, curr = L;
	//Find the kth last node
	while(ahead)
	{
		pre =  curr;
		curr = curr->next, ahead = ahead->next;
	}
	if(pre)
		pre->next = curr->next;
	else
		L= curr->next; //special case: delete L 
}