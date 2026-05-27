#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
	int n;
	cin >> n;

	long long d = 2;
	while (d * d <= n && n % d)
		d++;
	if (n % d)
		d = n;

	cout << n / d << " " << n - n / d << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}