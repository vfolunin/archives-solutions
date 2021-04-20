#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int n;
	cin >> n;

	if (!n)
		return 0;

	vector<int> pos(n);
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}

	bool antiarithmetic = 1;
	for (int a = 0; antiarithmetic && a < n; a++) {
		for (int b = a + 1; antiarithmetic && b < n; b++) {
			int c = b + (b - a);
			if (c >= n)
				break;
			antiarithmetic &= !(pos[a] < pos[b] && pos[b] < pos[c] || pos[a] > pos[b] && pos[b] > pos[c]);
		}
	}

	cout << (antiarithmetic ? "yes\n" : "no\n");
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}