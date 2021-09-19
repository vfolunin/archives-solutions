#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long res;
    cin >> res;

    while (1) {
        char op;
        cin >> op;

        if (op == '=')
            break;

        long long arg;
        cin >> arg;

        if (op == '+')
            res += arg;
        else if (op == '-')
            res -= arg;
        else if (op == '*')
            res *= arg;
        else
            res /= arg;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}