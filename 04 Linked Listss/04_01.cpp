#include "/Users/tshrjn/stdc++.h"
using namespace std;

template <typename T>
void append_node_and_advance(shared_ptr<node_t<T> > &head,
	shared_ptr<node_t<T> > &tail, shared_ptr<node_t<T> > &n){
	head ? tail->next = n: head = n;
	tail = n;
	n = n->next;
}

template <typename T>
shared_ptr<node_t<T> > merge_sorted_linked_lists(shared_ptr<node_t<T> > F,
shared_ptr<node_t<T> > L){
	shared_ptr<node_t<T> > sorted_head = nullptr, sorted_tail = nullptr;

	while(F && L)
	{
		append_node_and_advance(sorted_head, sorted_tail, F->data < L->data ? F : L);
	}

	while(F)
		append_node_and_advance(sorted_head, sorted_tail,F);

	while(L)
		append_node_and_advance(sorted_head, sorted_tail,L);
	return sorted_head;
}