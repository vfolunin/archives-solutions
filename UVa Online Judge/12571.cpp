#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, queryCount;
    cin >> size >> queryCount;

    set<int> args;
    for (int i = 0; i < size; i++) {
        int arg;
        cin >> arg;
        
        args.insert(arg & 255);
    }

    for (int i = 0; i < queryCount; i++) {
        int arg1;
        cin >> arg1;

        int res = 0;
        for (int arg2 : args)
            res = max(res, arg1 & arg2);

        cout << res << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}