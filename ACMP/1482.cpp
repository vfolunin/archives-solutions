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

	long long n;
	cin >> n;

	double num = 1, den = 3, res = 1;
	for (int i = 1; i < n && i < 100; i++) {
		res += num / den;
		num *= 4;
		den *= 9;
	}

	cout << fixed << res;
}