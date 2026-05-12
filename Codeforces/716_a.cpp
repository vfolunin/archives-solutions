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

	int size, limit;
	cin >> size >> limit;

	vector<int> a(size);
	int row = 0;
	for (int i = 0; i < a.size(); i++) {
		cin >> a[i];

		if (i && a[i] - a[i - 1] > limit)
			row = 1;
		else
			row++;
	}

	cout << row;
}