#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isAutomorphic(long long value) {
    string a = to_string(value), b = to_string(value * value);
    return b.substr(b.size() - a.size()) == a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    bool found = 0;
    for (int i = l; i <= r; i++) {
        if (isAutomorphic(i)) {
            found = 1;
            cout << i << " ";
        }
    }

    if (!found)
        cout << -1;
}