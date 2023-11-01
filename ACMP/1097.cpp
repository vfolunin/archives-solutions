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

	int a, b;
	cin >> a >> b;

	cout << max(a, b) << "\n";

	for (int i = 0; i < max(a, b); i++) {
		cout << min(a, b);

		for (int j = 0; j < min(a, b); j++) {
			if (a <= b)
				cout << " " << j + 1 << "-" << (i + j) % b + 1;
			else
				cout << " " << (i + j) % a + 1 << "-" << j + 1;
		}

		cout << "\n";
	}
}