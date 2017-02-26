#include "/Users/tshrjn/stdc++.h"

using namespace std;
const array<string, 10> M = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void phone_mnemonic_helper(string &num, int d, string &ans)
{
	if(d == num.size())
		cout<< ans<< endl;
	else
	{
		for(const char &c: M[num[d] - '0'])
		{
			ans[d] = c;
			phone_mnemonic_helper(num, d+1, ans);
		}
	}
}
void phone_mnemonic(string &num)
{
	string ans;
	ans.resize(num.size());
	phone_mnemonic_helper(num, 0, ans);
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	phone_mnemonic(s);
	return 0;
}