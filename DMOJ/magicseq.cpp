#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int size, int last) {
	static vector<vector<long long>> memo(200, vector<long long>(200, -1));
	long long &res = memo[size][last];
	if (res != -1)
		return res;

	if (size % 2 != last % 2)
		return res = 0;

	if (size == 1)
		return res = 1;

	res = 0;
	for (int prev = 1; prev < last; prev++)
		res += rec(size - 1, prev);
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	long long res = 0;
	for (int size = 1; size <= n; size++)
		for (int last = 1; last <= n; last++)
			res += rec(size, last);

	cout << res;
}