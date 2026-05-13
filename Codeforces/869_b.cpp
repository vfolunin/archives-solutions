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

	long long l, r;
	cin >> l >> r;

	long long res = 1;
	for (long long i = l + 1; res && i <= r; i++)
		res = (res * i) % 10;

	cout << res;
}