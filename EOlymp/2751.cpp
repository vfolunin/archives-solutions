#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
	int size;
	cin >> size;

	if (!size)
		return 0;

	vector<int> a(size);
	for (int &value : a)
		cin >> value;

	int res = 0;
	while (res < 1000) {
		auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
		if (*minIt == *maxIt)
			break;

		vector<int> d(a.size());
		for (int i = 0; i < a.size(); i++)
			d[i] = abs(a[i] - a[(i + 1) % a.size()]);
		a.swap(d);

		res++;
	}

	cout << "Case " << test << ": ";
	if (res < 1000)
		cout << res << " iterations\n";
	else
		cout << "not attained\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int test = 1; solve(test); test++);
}