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

	vector<int> count = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	int res = 0;

	while (n > 9) {
		res += count[n % 10];
		n /= 10;
	}
	res += count[n];

	cout << res;
}