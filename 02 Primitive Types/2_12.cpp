// 2_11 - Given n , return the primes from 1 to n
/* Things learnt:
1. primes.emplace_back(2);
*/
#include "/Users/tshrjn/stdc++.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

/*#define dim pair<int, int> // h x w
#define pos pair<int, int> // (x,y)
#define rect pair<pos, dim>
#define F first
#define S second

*/

class Rect
{
public:
	int x,y, h, w;	

	void print()  
	{
    	std::cout << "Rect: (x,y,h,w): " << this->x << ' ' << this->y << ' ' << this->h << ' '
         << this->w << endl;
  	}
};

bool is_intersect(Rect R, Rect S)
{
	return R.x <= S.x + S.w && R.x + R.w >= S.x &&
	R.y <= S.y + S.h && R.y + R.h <= S.y;

}
Rect rect_interection(Rect r, Rect s)
{
	if(is_intersect(r,s))
	{
		return { max(r.x, s.x), max(r.y, s.y),
				min(r.x +r.w, s.x +s.w) - max(r.x, s.x),
				min(r.y +r.h, s.y +s.h) - max(r.y, s.y)
			};
	}
	else
	{
		return {0, 0, -1, -1};
	}
}

void SmallTest() {
  Rect R1 = {0, 0, 2, 2}, R2 = {1, 1, 3, 3};
  auto result = rect_interection(R1, R2);
  assert(result.x == 1 && result.y == 1 && result.w == 1 &&
         result.h == 1);
  R1 = {0, 0, 1, 1}, R2 = {1, 1, 3, 3};
  result = rect_interection(R1, R2);
  assert(result.x == 1 && result.y == 1 && result.w == 0 &&
         result.h == 0);
  R1 = {0, 0, 1, 1}, R2 = {2, 2, 3, 3};
  result = rect_interection(R1, R2);
  assert(result.x == 0 && result.y == 0 && result.w == -1 &&
         result.h == -1);
}

int main(int argc, char const *argv[])
{
	Rect R1, R2;
	if (argc == 9) {
	  R1.x = atoi(argv[1]), R1.y = atoi(argv[2]), R1.w = atoi(argv[3]),
	  R1.h = atoi(argv[4]);
	  R2.x = atoi(argv[5]), R2.y = atoi(argv[6]), R2.w = atoi(argv[7]),
	  R2.h = atoi(argv[8]);
	} else {
	  return 0;
	  // default_random_engine gen((random_device())());
	  // uniform_int_distribution<int> dis(1, 100);
	  // R1.x = dis(gen), R1.y = dis(gen), R1.w = dis(gen),
	  // R1.h = dis(gen);
	  // R2.x = dis(gen), R2.y = dis(gen), R2.w = dis(gen),
	  // R2.h = dis(gen);
	}
	// Intersect rectangle.
	bool res = is_intersect(R1, R2);
	cout << std::boolalpha << is_intersect(R1, R2) << endl;
	Rect ans = rect_interection(R1, R2);
	ans.print();
	assert(res == false || (ans.h >= 0 && ans.w >= 0));
    return 0;
}