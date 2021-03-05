#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] <= (i ? a[i - 1] : 0)) {
            cout << "Case #" << test << ": It is not a B2-Sequence.\n\n";
            return 1;
        }
    }

    set<int> sums;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (sums.count(a[i] + a[j])) {
                cout << "Case #" << test << ": It is not a B2-Sequence.\n\n";
                return 1;
            }
            sums.insert(a[i] + a[j]);
        }
    }

    cout << "Case #" << test << ": It is a B2-Sequence.\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}