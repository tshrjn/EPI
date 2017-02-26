#include "/User/tshrjn/stdc++.h"

using namespace std;

template <typename T>
class Queue{
private:
	size_t  head, tail, count;
	vector<T> data;

public:
	Queue(size_t &cap = 8): head(0), tail(0), count(0), data({cap}) {}

	void enqueue(T &x){
		//dynamically resize due to data.size() limit
		if(count == data.size())
			data.resize(data.size << 1);

		//perform enqueue
		data[tail] = x;
		tail = (tail+1)% data.size(), ++count;
	}

	T dequeue(void){
		if(count)
		{
			--count;
			T ret = data[head];
			head = (head +1)% data.size();
			return ret;
		}
		throw length_error("empty queue");
	}

	size_t &size(void){
		return count;
	}
};