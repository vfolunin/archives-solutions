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

	int size;
	cin >> size;

	vector<int> a(size);
	for (int &value : a)
		cin >> value;

	int targetValue;
	cin >> targetValue;

	auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
	int res = 0;
	if (*minIt < targetValue)
		res += targetValue - *minIt;
	if (targetValue < *maxIt)
		res += *maxIt - targetValue;

	cout << res;
}