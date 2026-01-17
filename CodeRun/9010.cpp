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

    for (int d = 1; d * d <= b; d++) {
        if (b % d == 0 && (d + b / d + 2) * 2 == a) {
            cout << b / d + 2 << " " << d + 2;
            return 0;
        }
    }
}