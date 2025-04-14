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

    string l, r;
    cin >> l >> r;

    l = string(r.size() - l.size(), '0') + l;
    for (int i = 0; i < l.size(); i++) {
        if (l[i] != r[i]) {
            cout << l.size() - i;
            return 0;
        }
    }

    cout << 0;
}