#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int dfs(vector<int> &p, int i) {
    if (p[i] == -1)
        return 0;
    int to = p[i];
    p[i] = -1;
    return 1 + dfs(p, to);
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> p(n);
    for (int &x : p) {
        cin >> x;
        x--;
    }

    long long res = 1;
    for (int i = 0; i < n; i++)
        if (p[i] != -1)
            res = lcm(res, dfs(p, i));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}