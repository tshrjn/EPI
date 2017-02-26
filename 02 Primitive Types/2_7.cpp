// 2_7 - Base Changer
/* Things learnt:

*/
#include "/Users/tshrjn/stdc++.h"
using std::string;
using std::cin;


string BaseChanger (string s, int b1, int b2)
{
	bool is_negative = s[0] == '-';
	int x = 0;
	for (int i = is_negative; i < s.size(); ++i)
	{
		x += (isdigit(s[i])? s[i] - '0' : s[i] - '0' - 7 ) * std::pow(b1, s.size() - 1 - i);
	}

	string s2;
	while(x)
	{
		s2.push_back( x%b2 < 10 ? '0' + x%b2 : '0' + x%b2 + 7 );
		x /= b2;
	}
	if(s2.empty())
	{
		return {"0"}; //x is 0
	}

	if (is_negative)
	{
		s2.push_back('-');
	}

	reverse(s2.begin(), s2.end());
	return s2;
}

int StringToInt( string s)
{
	bool is_negative = s[0] == '-';
	int t = 0;
	for (int i = is_negative; i < s.size(); ++i)
	{
		if(48 <= int(s[i]) && int(s[i]) <= 57 )
		{
			t = t*10 + int(s[i]) - 48; 
		}
		else
			throw std::invalid_argument("illegal input");
		// if(isdigit (s[i]) )
		// {
		// 	t = t*10 + s[i] - '0'; 
		// }
		// else
		// 	return -1;
	}
	return is_negative ? -t : t;
}

string IntToString( int x)
{
	bool is_negative = false;
	if (x < 0)
	{
		x = -x, is_negative = true;
	}

	string s;
	while(x)
	{
		s.push_back('0' + x%10);
		x /=10;
	}
	if(s.empty())
	{
		return {"0"}; //x is 0
	}

	if (is_negative)
	{
		s.push_back('-');
	}

	reverse(s.begin(), s.end());
	return s;
}

int main(int argc, char const *argv[])
{
	int b1, b2;
	string s;
	std::cout << "Input Base-1: ";
	cin >> b1;
	std::cout << "\nInput String of Base-1: ";
	cin >> s;
	std::cout << "\nInput Base-2: ";
	cin >> b2;
	// while(!(cin >> n)){ //5th learning
	// 	cin.clear();
	// 	cin.ignore(std::numeric_limits< std::streamsize>::max(), '\n');
	// 	std::cout << "Invalid input.  Try again: ";
	// }
	std::cout << "\n Value in Base-" << b1 << ": " << s << std::endl;
	std::cout << "\n Value in Base-" << b2 << ": " << BaseChanger(s, b1, b2) << std::endl;

    return 0;
}