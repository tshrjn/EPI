#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
void deletion_from_list( shared_ptr< node_t<T> > &v )
{
	v->data = v->next->data;
	v->next = v->next->next;
}