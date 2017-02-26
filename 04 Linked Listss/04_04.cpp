#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
int count_len(shared_ptr<node_t<T> > L)
{
	int len = 0;
	while(L)
	{
		++len, L = L->next;
	}
	return len;
}

template <typename T>
void advance_list_by_k(shared_ptr<node_t<T> > &L, int k)
{
	while(k--)
		L=L->next;
}

template <typename T>
shared_ptr<node_t<T> > overlapping_no_cycle_lists(shared_ptr<node_t<T> > L1,
	shared_ptr<node_t<T> > L2)
{
	//Count the lenghts of L1 & L2
	int L1_len = count_len<T>(L1), L2_len = count_len<T>(L2);

	//Advance the longer linked list by the difference.
	advance_list_by_k(L1_len > L2_len ? L1:L2, abs(L1_len - L2_len));

	while(L1 && L2 && L1!=L2)
	{
		L1 = L1->next, L2 = L2->next;
	}
	return L1; //nullptr means no overlap between L1 & L2.
}