#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	vector<deque<string>> queue(2);
	for (int i = 0; i < 52; i++) {
		string card;
		cin >> card;

		if (card == "#")
			return 0;

		queue[i % 2].push_front(card);
	}

	map<char, int> cover = { {'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4} };
	deque<string> stack;

	int player = 0;
	while (1) {
		if (queue[player].empty())
			break;
		stack.push_back(queue[player].front());
		queue[player].pop_front();
		player ^= 1;

		while (cover.count(stack.back()[1])) {
			int coverCount = cover[stack.back()[1]];

			bool gameOver = 0, switched = 0;
			for (int i = 0; i < coverCount; i++) {
				if (queue[player].empty()) {
					gameOver = 1;
					break;
				}
				stack.push_back(queue[player].front());
				queue[player].pop_front();

				if (cover.count(stack.back()[1])) {
					player ^= 1;
					switched = 1;
					break;
				}
			}
			if (gameOver)
				break;
			if (switched)
				continue;

			player ^= 1;
			while (!stack.empty()) {
				queue[player].push_back(stack.front());
				stack.pop_front();
			}
			break;
		}
	}

	if (queue[0].empty())
		cout << 1 << setw(3) << queue[1].size() << "\n";
	else
		cout << 2 << setw(3) << queue[0].size() << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}