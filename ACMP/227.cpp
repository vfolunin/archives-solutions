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

	int a, b;
    cin >> a >> b;

    if (!a) {
        cout << (b ? -1 : 0);
        return 0;
    }

    if (a > 0 && b < 0 || a < 0 && b > 0 || a && !b || b % a) {
        cout << -1;
        return 0;
    }

    b /= a;

    int res = 0;
    for (int i = 2; i * i <= b; i++) {
        while (b % i == 0) {
            b /= i;
            res += i;
        }
    }
    if (b > 1)
        res += b;

    cout << res;
}