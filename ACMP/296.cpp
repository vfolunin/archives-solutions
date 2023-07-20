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

	int n;
	cin >> n;

	for (int k3 = 0; k3 * 3 <= n; k3++) {
		if ((n - k3 * 3) % 5 == 0) {
			cout << (n - k3 * 3) / 5 << " " << k3;
			break;
		}
	}
}