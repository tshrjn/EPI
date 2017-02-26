#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
void approximate_sort(istringstream &sin, int &k)
{	
	priority_queue<T, vector<T>, greater<T> > min_heap;

	//First push k elements into the min heap
	T x;
	for (int i = 0; i < k && sin >> x; ++i)
	{
		// min_heap.emplace(x);
		min_heap.push(x);
	}

	//Extract the minimum one for every incoming element
	while(sin >> x)
	{
		min_heap.push(x);
		cout<<min_heap.top()<<endl;
		min_heap.pop();
	}

	//Extract the remaining elements in the loop 
	while(min_heap.size())
	{
		cout<<min_heap.top()<<endl;
		min_heap.pop();		
	}
}