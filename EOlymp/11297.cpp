#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(int x, int y) {
	if (x <= 0 || y <= 0)
		return 1;

	static vector<vector<long long>> memo(26, vector<long long>(26, -1));
	long long &res = memo[y][x];
	if (res != -1)
		return res;

	if (x <= y)
		return res = f(x - 1, y) + f(x, y - 1) + 1;
	else
		return res = f(x, y / 2) + 2;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y;
	cin >> x >> y;

	cout << f(x, y);
}