#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> r(n), stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && a[stack.back()] > a[i]) {
            r[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    while (!stack.empty()) {
        r[stack.back()] = n;
        stack.pop_back();
    }

    vector<int> l(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && a[stack.back()] > a[i]) {
            l[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    while (!stack.empty()) {
        l[stack.back()] = -1;
        stack.pop_back();
    }

    long long res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, a[i] * (r[i] - l[i] - 1LL));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}