#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
void find_kth_largest_stream(istringstream &sin, int &k)
{	
	priority_queue<T, vector<T>, greater<T> > min_heap;

	//the first k elemennts, output the minimum element
	T x;
	for (int i = 0; i < k && sin >> x; ++i)
	{
		min_heap.emplace(x);
		cout<<min_heap.top() <<endl;
	}
	cout<<"After the first k elements, now outputing the kth largest one\n";
	//After the first k elements, output the kth largest one
	while(sin >> x)
	{
		if(min_heap.top() < x)
		{
			min_heap.pop();
			min_heap.emplace(x);
		}
		cout<<min_heap.top()<<endl;
	}
}