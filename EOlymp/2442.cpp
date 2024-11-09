#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int eggs, int floors, int drops) {
	long long product = 1, sum = 0;
	for (int i = 1; i <= eggs && sum < floors; i++) {
		product *= drops - i + 1;
		product /= i;
		sum += product;
	}
	return sum >= floors;
}

void solve() {
	int test, eggs, floors;
	cin >> test >> eggs >> floors;

	int l = 0, r = floors;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (can(eggs, floors, m))
			r = m;
		else
			l = m;
	}

	cout << test << " " << r << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		solve();
}