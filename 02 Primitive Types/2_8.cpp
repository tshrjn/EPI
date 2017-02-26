// 2_7 - Base Changer
/* Things learnt:

*/
#include "/Users/tshrjn/stdc++.h"
using std::string;
using std::cin;

int ssDecodeColID (string s)
{
	int x = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		x += (s[i] - 'A' + 1) * std::pow(26, s.size() - 1 - i);
	}
	return x;
}


int main(int argc, char const *argv[])
{
	string s;
	std::cout << " Input id String of Column: ";
	cin >> s;
	std::cout << "\n Input Base-2: ";
	std::cout << "\n Value in Base-10: " << ssDecodeColID(s) << std::endl;

    return 0;
}