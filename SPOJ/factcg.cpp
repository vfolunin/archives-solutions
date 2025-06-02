#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> factorize(int n) {
    static vector<vector<int>> memo(1e5 + 1);
    vector<int> &factorization = memo[n];
    if (n == 1 || !factorization.empty())
        return factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n != 1)
        factorization.push_back(n);

    return factorization;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << 1;
    for (int p : factorize(n))
        cout << " x " << p;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}