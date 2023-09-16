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

	long long res = 1;
	while (n > 4) {
		n -= 3;
		res *= 3;
	}
	res *= n;

	cout << res;
}