#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isComposite(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 1;

    return 0;
}

vector<int> getCompositeFib() {
    vector<int> fib = { 1, 1 };
    for (int i = 2; fib.back() < 1e5; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    
    vector<int> res;
    for (int value : fib)
        if (isComposite(value))
            res.push_back(value);
    return res;
}

void solve() {
    int value;
    cin >> value;

    static vector<int> compositeFib = getCompositeFib();

    cout << (binary_search(compositeFib.begin(), compositeFib.end(), value) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}