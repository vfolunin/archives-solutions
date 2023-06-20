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

    vector<int> a(10);
    for (int i = 0; i < 6; i++) {
        int digit;
        cin >> digit;
        a[digit] = 1;
    }
    a[6] |= a[9];
    a[9] |= a[6];

    vector<int> b(10);
    for (int i = 0; i < 6; i++) {
        int digit;
        cin >> digit;
        b[digit] = 1;
    }
    b[6] |= b[9];
    b[9] |= b[6];

    for (int i = 1; i < 100; i++) {
        int d1 = i / 10, d2 = i % 10;
        if ((!a[d1] || !b[d2]) && (!a[d2] || !b[d1])) {
            cout << i - 1;
            return 0;
        }
    }

    cout << 99;
}