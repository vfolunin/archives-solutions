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
 
	int aSize, bSize;
	cin >> aSize >> bSize;

	vector<int> a(aSize);
	for (int &value : a)
		cin >> value;
	sort(a.begin(), a.end());

	vector<int> b(bSize);
	for (int &value : b)
		cin >> value;
	sort(b.begin(), b.end());

	for (int digit = 0; digit < 10; digit++) {
		if (binary_search(a.begin(), a.end(), digit) && binary_search(b.begin(), b.end(), digit)) {
			cout << digit;
			return 0;
		}
	}

	cout << min(a[0], b[0]) << max(a[0], b[0]);
}