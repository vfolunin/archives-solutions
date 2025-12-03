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

	int res = 0;
	for (int i = 0; i < size; i++) {
		int a, b;
		cin >> a >> b;

		if (abs(a - b) <= limit) {
			res += max(a, b);
		} else {
			int c;
			cin >> c;

			res += c;
		}
	}

	cout << res;
}