#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
	int itemCount, heightLimit, t1, t2;
	cin >> itemCount >> heightLimit >> t1 >> t2;

	vector<int> height(itemCount);
	for (int &w : height)
		cin >> w;
	sort(height.begin(), height.end());

	int res;
	if (t1 * 2 <= t2) {
		res = itemCount * t1;
	} else {
		res = 0;
		for (int l = 0, r = itemCount - 1; l <= r; l++, r--) {
			while (l < r && height[l] + height[r] >= heightLimit) {
				r--;
				res += t1;
			}
			if (l < r)
				res += t2;
			else
				res += t1;
		}
	}

	cout << "Case " << test << ": " << res << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int test = 1; test <= n; test++)
		solve(test);
}