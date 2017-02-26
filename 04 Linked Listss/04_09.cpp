#include "/Users/tshrjn/stdc++.h"

template <typename T> //uses O(n) storage & O(n) time
shared_ptr<node_t<T> >recursive_reverse_linked_list(shared_ptr<node_t<T> > &head)
{
	if(!head || !head->next)
		return head;

	shared_ptr<node_t<T> > new_head = recursive_reverse_linked_list(head->next);
	head->next->next = head;
	head->next = nullptr
	return new_head;
}

template <typename T>
shared_ptr<node_t<T> > iterative_reverse_linked_list( shared_ptr<node_t<T> > &head)
{
	shared_ptr<node_t<T> > prev = nullptr, curr = head;
	while(curr)
	{
		shared_ptr<node_t<T> > temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}