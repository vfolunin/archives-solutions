#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n) {
    static vector<int> memo(1e6, -1);
    int &res = memo[n];
    if (res != -1)
        return res;

    res = n == 1;

    int squareSum = 0;
    for (; n; n /= 10)
        squareSum += (n % 10) * (n % 10);
    
    return res = rec(squareSum);
}

vector<int> prepare() {
    vector<int> res;
    for (int n = 1; res.size() < 500; n++)
        if (rec(n))
            res.push_back(n);
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << res[n - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}