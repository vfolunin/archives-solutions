#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int factorialPower(int n, int d) {
	int res = 0;
	while (n) {
		n /= d;
		res += n;
	}
	return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cout << min(factorialPower(n, 2), factorialPower(n, 5));
}