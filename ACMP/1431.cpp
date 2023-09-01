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

	long long n, a;
	cin >> n >> a;

	for (int i = 0; i < 3; i++) {
		long long b;
		cin >> b;

		a = max(0LL, a + b - n);
	}

	cout << a;
}