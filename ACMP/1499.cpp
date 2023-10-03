#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(int n) {
	cout << "? " << n << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int l = 0, r = 1e9;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (ask(m) == m)
			l = m;
		else
			r = m;
	}

	cout << "! " << r << endl;
}