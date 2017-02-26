#include "/Users/tshrjn/stdc++.h"

template <typename T>
void connect_a_next_to_b_advance_a(shared_ptr<node_t<T> > &a, shared_ptr<node_t<T> > &b)
{
	shared_ptr<node_t<T> > temp = a->next;
	a->next = b;
	a = temp;
}

template <typename T>
shared_ptr<node_t<T> > zipping_linked_list(shared_ptr<node_t<T> > &L)
{
	shared_ptr<node_t<T> > slow = L, fast = L, pre_slow = nullptr;
	//Find middle of L
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			pre_slow = slow;
			slow=slow->next, fast = fast->next;
		}
	}
	if(!pre_slow)
		return L; //contains only 1 node in the List

	pre_slow->next = nullptr; //split lists into 2 lists
	shared_ptr<node_t<T> > reverse = iterative_reverse_linked_list(slow), curr = L;

	//Zipping the list
	while(curr && reverse)
	{
		//connect curr->next to reverse & advance the curr
		connect_a_next_to_b_advance_a(curr, reverse);
		if(curr)
			//connect reverse->next to curr, and advance reverse
			connect_a_next_to_b_advance_a(reverse, curr);
	}
	return L;
}