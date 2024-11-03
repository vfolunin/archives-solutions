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

	a.erase(unique(a.begin(), a.end()), a.end());

	int res = 0;
	for (int i = 1; i < a.size(); i++) {
		for (int j = i; j && a[j - 1] > a[j]; j--) {
			swap(a[j - 1], a[j]);
			res++;
		}
	}

	cout << res;
}