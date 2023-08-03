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

	int x, y;
	cin >> x >> y;

	if (abs(x) < 1e9 && abs(y) < 1e9) {
		cout << "YES\n";
		cout << x - 1 << " " << y - 1 << "\n";
		cout << x << " " << y + 1 << "\n";
		cout << x + 1 << " " << y << "\n";
	} else {
		cout << "NO";
	}
}