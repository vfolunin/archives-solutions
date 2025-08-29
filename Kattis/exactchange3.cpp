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

    int res = 0;
    for (int i = 0; i < l.size(); i++) {
        if (l[i] != r[i]) {
            res += l.size() - i;
            break;
        }
        res += l[i] == '1';
    }

    cout << res;
}