#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename t>
shared_ptr<node_t<T> > has_cycle(shared_ptr<node_t<T> > &head)
{
	shared_ptr<node_t<T> > fast = head, slow = head;

	while(slow && slow->next && fast && fast->next && fast->next->next)
	{
		slow = slow->next, fast = fast->next->next;
		//Found cycle
		if (slow == fast){
			//Cal. cycle len
			int cycle_len = 0;
			do{
				++cycle_len;
				fast= fast->next;
			}while(slow != fast);

			//Try to find the start of the cycle
			slow = head, fast = head;
			//Fast pointers advances cycle_len first
			while(cycle_len--)
			{
				fast = fast->next;
			}
			//Both pointers advance at the same time
			while(slow != fast)
			{
				slow = slow->next, fast = fast->next;
			}
			return slow; // start of cycle
		}
		return nullptr; // No loop
	}
}