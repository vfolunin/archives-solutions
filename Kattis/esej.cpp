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

    for (int i = 1; i <= r; i++) {
        for (int code = i; code; code /= 26)
            cout << (char)('a' + code % 26);
        cout << " ";
    }
}