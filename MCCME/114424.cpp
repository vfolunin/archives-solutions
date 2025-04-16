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

	int size, skip;
	cin >> size >> skip;

	vector<int> a(size);
	for (int &value : a)
		cin >> value;

	vector<long long> res(size);
	res[0] = a[0];
	for (int i = 1; i < size; i++) {
		res[i] = a[i] + (i - skip - 1 >= 0 ? res[i - skip - 1] : 0);
		res[i] = max(res[i], res[i - 1]);
	}

	cout << res.back();
}