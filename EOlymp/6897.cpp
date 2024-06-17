#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int collatz(long long n) {
    static vector<int> memo(1e6 + 1);
    if (n >= memo.size())
        return 1 + collatz(n % 2 ? 3 * n + 1 : n / 2);

    int &res = memo[n];
    if (res)
        return res;

    if (n == 1)
        return res = 1;

    return res = 1 + collatz(n % 2 ? 3 * n + 1 : n / 2);
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << collatz(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}