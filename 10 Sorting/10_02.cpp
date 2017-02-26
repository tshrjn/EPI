#include "/Users/tshrjn/stdc++.h"

using namespace std;

template <typename T>
void indeirect_sort(string &file_name)
{
	//Sotre file records in A
	ifstream ifs(file_name.c_str());
	vector<T> A;
	T x;
	while(ifs >> x)
		A.emplace_back(x);

	//Initialise P
	vector<T*> P;
	for(T &a : A)
		P.emplace_back(&a);

	//indirect sort file
	sort(P.begin(), P.end(), [](T* a, T* b) -> bool{ return *a < *b;});

	//Output File
	ofstream ofs(file_name.c_str());
	for(T* p: P)
		ofs << p << endl;
}