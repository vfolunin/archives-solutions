#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void solve() {
    int mod;
    cin >> mod;

    unordered_map<int, int> pos;
    vector<int> fib = { 0, 1, 1 };

    for (int i = 2; 1; i++) {
        fib[0] = fib[1];
        fib[1] = fib[2];
        fib[2] = (fib[0] + fib[1]) % mod;

        if (pos.count(fib[2])) {
            cout << pos[fib[2]] << "\n";
            break;
        }

        pos[fib[2]] = i;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}