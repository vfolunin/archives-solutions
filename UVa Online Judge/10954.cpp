#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    long long res = 0;
    while (s.size() > 1) {
        int a = *s.begin();
        s.erase(s.begin());
        int b = *s.begin();
        s.erase(s.begin());
        res += a + b;
        s.insert(a + b);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}