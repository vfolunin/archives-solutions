#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
	int aSize, bSize;
	cin >> aSize >> aSize >> bSize;

	map<int, int> aPos;
	for (int i = 0; i <= aSize; i++) {
		int x;
		cin >> x;
		aPos[x] = i;
	}

	vector<int> b;
	for (int i = 0; i <= bSize; i++) {
		int x;
		cin >> x;
		if (aPos.count(x))
			b.push_back(aPos[x]);
	}

	vector<int> last(bSize + 1, 1e9);
	for (int x : b)
		*lower_bound(last.begin(), last.end(), x) = x;

	int lisLength = bSize + 1;
	while (last[lisLength - 1] == 1e9)
		lisLength--;

	cout << "Case " << test << ": " << lisLength << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int test = 1; test <= n; test++)
		solve(test);
}