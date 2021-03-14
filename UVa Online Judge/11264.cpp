#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int coinCount;
    cin >> coinCount;

    vector<int> coin(coinCount);
    for (int &c : coin)
        cin >> c;

    long long sum = 0;
    int res = 1;
    for (int i = 1; i < coinCount; i++) {
        if (sum + coin[i - 1] < coin[i]) {
            sum += coin[i - 1];
            res++;
        }
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