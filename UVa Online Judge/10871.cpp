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

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 0, r = len - 1; r < n; l++, r++) {
            if (isPrime(p[r] - (l ? p[l - 1] : 0))) {
                cout << "Shortest primed subsequence is length " << len << ":";
                for (int i = l; i <= r; i++)
                    cout << " " << p[i] - (i ? p[i - 1] : 0);
                cout << "\n";
                return;
            }
        }
    }

    cout << "This sequence is anti-primed.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}