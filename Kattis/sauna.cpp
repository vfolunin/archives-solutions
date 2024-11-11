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

	int l = -1e9, r = 1e9;
	for (int i = 0; i < size; i++) {
		int cl, cr;
		cin >> cl >> cr;

		l = max(l, cl);
		r = min(r, cr);
	}

	if (l <= r)
		cout << r - l + 1 << " " << l;
	else
		cout << "bad news";
}