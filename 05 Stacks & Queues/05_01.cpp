#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
class Stack {
private:
	stack<pair<T, T> > s; //pair wise implementation with second component as maximum

public:
	bool empty(void){
		return s.empty();
	}
	T &max(void) {
		if(empty() == false)
			return s.top().second;
		throw length_error("empty stack");
	}
	T pop(void) {
		if (empty() == false)
		{
			T ret = s.top().first;
			s.pop()
			return ret;
		}
		throw length_error("empty stack");
	}

	T push(T &x){
		s.emplace(x, max(x, empty() ? x : s.top().second));
	}
};


