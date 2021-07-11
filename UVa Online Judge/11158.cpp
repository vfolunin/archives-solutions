#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    deque<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());
    deque<int> b = { a.front(), a.back() };
    a.pop_front();
    a.pop_back();

    while (!a.empty()) {
        int v1 = abs(a.front() - b.front());
        int v2 = abs(a.front() - b.back());
        int v3 = abs(a.back() - b.front());
        int v4 = abs(a.back() - b.back());

        if (v1 >= v2 && v1 >= v3 && v1 >= v4) {
            b.push_front(a.front());
            a.pop_front();
        } else if (v2 >= v1 && v2 >= v3 && v2 >= v4) {
            b.push_back(a.front());
            a.pop_front();
        } else if (v3 >= v1 && v3 >= v2 && v3 >= v4) {
            b.push_front(a.back());
            a.pop_back();
        } else {
            b.push_back(a.back());
            a.pop_back();
        }
    }

    int res = 0;
    for (int i = 0; i + 1 < n; i++)
        res += abs(b[i] - b[i + 1]);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}