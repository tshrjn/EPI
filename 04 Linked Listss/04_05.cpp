#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
shared_ptr<node_t<T> > overlapping_lists(shared_ptr<node_t<T> > L1,
	shared_ptr<node_t<T> >  L2)
{
	//Store start of cycle if any
	shared_ptr<node_t<T> > s1 = has_cycle<T>(L1), s2 = has_cycle<T>(L2);

	if(!s1 && !s2) //No cycle in both
		return overlapping_no_cycle_lists(L1, L2);
	else if(s1 && s2) // Both have cycles
	{
		shared_ptr<node_t<T> > temp = s2;
		do{
			temp = temp->next;
		} while( temp !=s1 && temp != s2)
		return temp == s1 ? s1 : nullptr; //First node of the loop
	}
	return nullptr; //one list has cycle, one list has no cycle
}