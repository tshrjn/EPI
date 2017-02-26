// 2_6
/* Things learnt:
1. Class String act like vectors ( & are vectors)
2. vector_name.reverse()
3. -x
4. Multiple assignments on same line: 
	x = -x, is_negative = true;
5. Handling wrong cin input (for int in this case)
*/
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <sstream>

using std::string;
using std::cin;

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

	string s;
	std::cout << "Input String: ";
	cin >> s;
	printf("Int of String %s is %d\n", s.c_str(), StringToInt(s) );

	std::cout << "\nInput Int: ";
	int n;
	while(!(cin >> n)){ //5th learning
		cin.clear();
		cin.ignore(std::numeric_limits< std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	// std::cin >> n;
	printf("String of int %d is %s\n", n, IntToString(n).c_str() );

    return 0;
}