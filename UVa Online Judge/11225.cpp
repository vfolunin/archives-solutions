#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
	int cardCount;
	cin >> cardCount;

	int score = 0, oudlers = 0;
	for (int i = 0; i < cardCount; i++) {
		string value;
		cin >> value;

		if (value == "fool") {
			score += 9;
			oudlers++;
			continue;
		}

		string suit;
		cin >> suit >> suit;

		if ((value == "one" || value == "twenty-one") && suit == "trumps") {
			score += 9;
			oudlers++;
		} else if (value == "king") {
			score += 9;
		} else if(value == "queen") {
			score += 7;
		} else if(value == "knight") {
			score += 5;
		} else if(value == "jack") {
			score += 3;
		} else {
			score++;
		}
	}

	vector<int> penalty = { 112, 102, 82, 72 };
	score -= penalty[oudlers];

	if (test > 1)
		cout << "\n";
	cout << "Hand #" << test << "\n";
	if (score < 0)
		cout << "Game lost by " << -score / 2 << " point(s).\n";
	else
		cout << "Game won by " << score / 2 << " point(s).\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int test = 1; test <= n; test++)
		solve(test);
}