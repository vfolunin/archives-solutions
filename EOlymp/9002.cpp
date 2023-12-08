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

	long long n, a, b;
	cin >> n >> a >> b;

	long long res = n / 2 * (a + b);
	if (n % 2)
		res += max(a, b);

	cout << res;
}