#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
bool is_linked_list_a_palindrome(shared_ptr<node_t<T> > L)
{
	//find the middle of L
	shared_ptr<node_t<T> > slow = L, fast = L;
	while(fast)
	{
		fast = fast->next;
		if(fast)
			fast = fast->next, slow = slow->next;
	}

	//compare first half & reversed second half lists
	shared_ptr<node_t<T> > reverse = iterative_reverse_linked_list<T>(slow);
	while(L && reverse)
	{
		if(reverse->data != L->data)
			return false;
		else
			reverse = reverse->next, L=L->next;
	}
	return true;
}