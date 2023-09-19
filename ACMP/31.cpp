#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int size, targetCount;
	cin >> size >> targetCount;

	vector<int> a(size);
	iota(a.begin(), a.end(), 0);

	int res = 0;
	do {
		int count = 0;
		for (int i = 0; i < a.size(); i++)
			count += a[i] == i;
		res += count == targetCount;
	} while (next_permutation(a.begin(), a.end()));

	cout << res;
}