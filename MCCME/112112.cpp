#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	int eventCount, cityCount;
	cin >> eventCount >> cityCount;

	vector<set<int>> cityStones(cityCount);
	set<pair<int, int>> bestStones;
	for (int i = 0; i < eventCount; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int city, stone;
			cin >> city >> stone;
			city--;

			if (!cityStones[city].empty())
				bestStones.erase({ *cityStones[city].begin(), city });
			cityStones[city].insert(stone);
			bestStones.insert({ *cityStones[city].begin(), city });
		} else {
			auto [stone, city] = *prev(bestStones.end());
			bestStones.erase(prev(bestStones.end()));

			cityStones[city].erase(cityStones[city].begin());
			if (!cityStones[city].empty())
				bestStones.insert({ *cityStones[city].begin(), city });

			cout << stone << "\n";
		}
	}
}