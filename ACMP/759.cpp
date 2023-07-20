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

	int size, count;
	cin >> size >> count;

	vector<int> a(size);
	for (int &value : a)
		cin >> value;

	sort(a.rbegin(), a.rend());

	int res = 0;
	for (int i = 0; i < count && a[i] > 0; i++)
		res += a[i];

	cout << res;
}