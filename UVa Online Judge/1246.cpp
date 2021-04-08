#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int divisorCount(int n) {
    int d = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d++;
            if (i * i != n)
                d++;
        }
    }
    return d;
}

vector<int> prepare() {
    vector<int> p;
    for (int i = 1; i <= 10000; i++)
        if (isPrime(divisorCount(i)))
            p.push_back(i);
    return p;
}

void solve() {
    int l, r;
    cin >> l >> r;

    static vector<int> p = prepare();

    bool found = 0;
    for (int i = lower_bound(p.begin(), p.end(), l) - p.begin(); i < p.size() && p[i] <= r; i++) {
        if (found)
            cout << " ";
        else
            found = 1;
        cout << p[i];
    }
    if (!found)
        cout << -1;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}