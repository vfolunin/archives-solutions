#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, q;
    cin >> n >> q;

    if (!n && !q)
        return 0;

    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        s.erase(s.lower_bound(l), s.upper_bound(r));
        auto it = s.lower_bound(l);

        if (it == s.begin()) {
            cout << "*";
        } else {
            it--;
            cout << *it;
            it++;
        }
        cout << " ";

        if (it == s.end()) {
            cout << "*";
        } else {
            cout << *it;
        }
        cout << "\n";
    }

    cout << "-\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}