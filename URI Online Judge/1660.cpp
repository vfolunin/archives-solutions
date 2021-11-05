#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n, a, b;
    if (!(cin >> n >> a >> b))
        return 0;

    map<int, int> seen;
    int x = 0;
    while (seen[x] < 2) {
        seen[x]++;
        x = (a * x % n * x % n + b) % n;
    }

    long long res = n;
    for (auto &[_, times] : seen)
        res -= times == 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}