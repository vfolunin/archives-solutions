#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int f(int x, int y) {
	if (x <= 0 || y <= 0)
		return 0;

	static vector<vector<int>> memo(51, vector<int>(51, -1));
	int &res = memo[y][x];
	if (res != -1)
		return res;

	if (x <= y)
		return res = f(x - 1, y - 2) + f(x - 2, y - 1) + 2;
	else
		return res = f(x - 2, y - 2) + 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y;
	cin >> x >> y;

	cout << f(x, y);
}