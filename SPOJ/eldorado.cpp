#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
	int size, targetLen;
	cin >> size >> targetLen;

	if (!size)
		return 0;

	vector<int> a(size);
	for (int &value : a)
		cin >> value;

	vector<vector<long long>> ways(size, vector<long long>(targetLen + 1));
	long long res = 0;
	for (int i = 0; i < size; i++) {
		ways[i][1] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				for (int len = 2; len <= targetLen; len++)
					ways[i][len] += ways[j][len - 1];
		res += ways[i][targetLen];
	}

	cout << res << "\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (solve());
}