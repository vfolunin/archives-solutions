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

	int size;
	cin >> size;

	vector<long long> a(size), b(size);
	for (int i = 0; i < size; i++)
		cin >> a[i] >> b[i];

	vector<int> order(a.size());
	iota(order.begin(), order.end(), 0);
	stable_sort(order.begin(), order.end(), [&](int lhs, int rhs) {
		return a[lhs] * b[rhs] < a[rhs] * b[lhs];
	});

	for (int i : order)
		cout << i + 1 << " ";
}