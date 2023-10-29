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

	int speedCount;
	cin >> speedCount;

	vector<int> speeds(speedCount);
	for (int &speed : speeds)
		cin >> speed;

	sort(speeds.begin(), speeds.end());
	long long res = 0;

	while (speeds.size() > 3) {
		int a = speeds[0];
		int b = speeds[1];
		int y = speeds[speeds.size() - 2];
		int z = speeds[speeds.size() - 1];

		res += min(b + a + z + b, y + a + z + a);

		speeds.pop_back();
		speeds.pop_back();
	}

	if (speeds.size() <= 2)
		res += speeds.back();
	else
		res += speeds[0] + speeds[1] + speeds[2];

	cout << res;
}