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

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++) {
        if (i > 10)
            cout << i << " 0\n";
        else
            cout << i << " " << (3 * i + 4) / ((1 << i) - 1) << "\n";
    }
}