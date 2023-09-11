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

	int n, k;
	cin >> n >> k;

	if (n % k) {
		cout << 0;
		return 0;
	}

	long long res = 1;
	for (int i = 2; i <= k; i++)
		res *= i;

	cout << res;
}