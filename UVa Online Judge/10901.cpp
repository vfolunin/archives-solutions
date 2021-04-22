#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
	int ferryCapacity, crossingTime, carCount;
	cin >> ferryCapacity >> crossingTime >> carCount;

	queue<pair<int, int>> bankQueue[2];
	for (int i = 0; i < carCount; i++) {
		int time;
		string bank;
		cin >> time >> bank;
		if (bank == "left")
			bankQueue[0].push({ time, i });
		else
			bankQueue[1].push({ time, i });
	}

	int bank = 0, time = 0;
	vector<int> res(carCount);

	while (!bankQueue[0].empty() || !bankQueue[1].empty()) {
		if (!bankQueue[bank ^ 1].empty() &&
			(bankQueue[bank].empty() || bankQueue[bank].front().first > time && bankQueue[bank].front().first > bankQueue[bank ^ 1].front().first)) {			
			time = max(time, bankQueue[bank ^ 1].front().first) + crossingTime;
			bank ^= 1;
			continue;
		}
		if (!bankQueue[bank].empty()) {
			if (bankQueue[bank ^ 1].empty() || bankQueue[bank].front().first <= bankQueue[bank ^ 1].front().first)
				time = max(time, bankQueue[bank].front().first);
			for (int i = 0; i < ferryCapacity && !bankQueue[bank].empty() && bankQueue[bank].front().first <= time; i++) {
				res[bankQueue[bank].front().second] = time + crossingTime;
				bankQueue[bank].pop();
			}
		}
		time += crossingTime;
		bank ^= 1;
	}

	if (test)
		cout << "\n";
	for (int t : res)
		cout << t << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve(i);
}