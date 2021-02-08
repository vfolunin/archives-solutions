#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, ccwk, cwk;
    cin >> n >> ccwk >> cwk;

    if (!n && !ccwk && !cwk)
        return 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    int ccwi = n - 1, cwi = 0;
    bool first = 1;

    while (1) {
        for (int i = 0; i < ccwk; i++) {
            ccwi = (ccwi + 1) % v.size();
            while (v[ccwi] == -1)
                ccwi = (ccwi + 1) % v.size();
        }

        for (int i = 0; i < cwk; i++) {
            cwi = (cwi + v.size() - 1) % v.size();
            while (v[cwi] == -1)
                cwi = (cwi + v.size() - 1) % v.size();
        }

        if (first)
            first = 0;
        else
            cout << ",";

        cout << setw(3) << v[ccwi];
        if (cwi != ccwi)
            cout << setw(3) << v[cwi];

        v[ccwi] = -1;
        if (!--n)
            break;

        if (cwi != ccwi) {
            v[cwi] = -1;
            if (!--n)
                break;
        }
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}