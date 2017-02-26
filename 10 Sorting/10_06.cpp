#include "/Users/tshrjn/stdc++.h"

using namespace std;

class Player{
public:
	int height;
	bool operator<(Player &that){
		return height < that.height;
	}
}

class Team{
private:
	vector<int> members;

	vector<int> sortMembersByHeight()
	{
		vector<int> sorted_members(members);
		sort(sorted_members.begin(), sorted_members.end());
		return sorted_members;
	}

public:
	bool operator<(Team &that){
		vector<int> this_sorted(sortMembersByHeight());
		vector<int> that_sorted(that.sortMembersByHeight());
		for(int i =0; i <this_sorted.size() && i <  that_sorted.szie(); ++i)
			if(this_sorted[i] < that_sorted[i])
				return false;
		return true;
	}
}