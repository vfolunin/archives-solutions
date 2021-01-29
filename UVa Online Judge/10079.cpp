#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int f91(int n) {
    if (n > 100)
        return n - 10;
    static vector<int> memo(101, -1);
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = f91(f91(n + 11));
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "f91(" << n << ") = " << f91(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}