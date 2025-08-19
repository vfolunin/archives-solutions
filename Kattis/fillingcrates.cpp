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

    for (int d = 2; d * d <= n; d++) {
        if (n % d)
            continue;

        int d2 = n / d;
        if (d2 >= 2) {
            cout << d << "x" << d2;
            return 0;
        }
    }

    if (n > 11)
        cout << "3x3 2x" << (n - 9) / 2;
    else
        cout << "impossible";
}