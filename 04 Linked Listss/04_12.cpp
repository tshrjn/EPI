#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
shared_ptr<node_t<T> > copy_postings_list(shared_ptr<node_t<T> > &L)
{
	//Return empty list id L is nullptr
	if(!L)
		return nullptr;

	//1st stage: copy nodes from L
	shared_ptr<node_t<T> > p =L;
	while(p)
	{
		auto temp = shared_ptr<node_t<T> >(new node_t<T>{p->data, p->next, nullptr});
		p->next = temp;
		p = temp->next;	
	}

	//2nd stage: update the jump field
	p = L;
	while(p)
	{
		if(p->jump)
			p->next->jump = p->jump->next;
		p = p->next->next;
	}

	//3rd stage: reset the next fields
	p = L;
	shared_ptr<node_t<T> > copied = p->next;
	while(p->next)
	{
		shared_ptr<node_t<T> > temp = p->next;
		p->next = temp->next;
		p = temp;
	}
	return copied;
}