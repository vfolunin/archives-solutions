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

    string cur, res;
    for (char c; cin >> c;) {
        if (isdigit(c) && (c != '0' || !cur.empty())) {
            cur += c;
        } else {
            if (res.size() < cur.size() || res.size() == cur.size() && res < cur)
                res = cur;
            cur.clear();
        }
    }
    if (res.size() < cur.size() || res.size() == cur.size() && res < cur)
        res = cur;

    cout << res;
}