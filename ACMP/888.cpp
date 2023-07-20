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

	int problemCount;
	cin >> problemCount;

	int score = 3;
	long long res = 0;

	for (int i = 0; i < problemCount; i++) {
		int rightAnswer;
		cin >> rightAnswer;

		if (rightAnswer) {
			res += score;
			score++;
		} else {
			score = max(score - 3, 3);
		}
	}

	cout << res;
}