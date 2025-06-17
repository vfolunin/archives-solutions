#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(int value) {
    cout << "1 " << value << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int l = 0, r;
    cin >> r;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (ask(m))
            r = m;
        else
            l = m;
    }

    cout << "2 " << r << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        solve();
}