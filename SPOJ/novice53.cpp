#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n) {
    static vector<int> memo(1e5 + 1, -1);
    int &res = memo[n];
    if (res != -1)
        return res;

    if (!n)
        return res = 2;

    for (int i = 1; i * i <= n; i++)
        if (rec(n - i * i) == 2)
            return res = 1;

    return res = 2;
}

void solve() {
    int n;
    cin >> n;

    cout << (rec(n) == 1 ? "Aayush\n" : "Akash\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}