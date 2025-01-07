#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> a = { n };
    for (int i = n - 1; i; i--) {
        a.push_front(i);
        for (int j = 0; j < i; j++) {
            a.push_front(a.back());
            a.pop_back();
        }
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}