#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int mod;

bool compare(int a, int b) {
    int ra = a % mod;
    int rb = b % mod;
    int ta = (a % 2 + 2) % 2;
    int tb = (b % 2 + 2) % 2;

    if (ra != rb)
        return ra < rb;
    if (ta != tb)
        return ta;
    if (ta)
        return a > b;
    return a < b;
}

bool solve() {
    int n;
    cin >> n >> mod;

    if (!n && !mod) {
        cout << "0 0\n";
        return 0;
    }

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    sort(v.begin(), v.end(), compare);

    cout << n << " " << mod << "\n";
    for (int x : v)
        cout << x << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}