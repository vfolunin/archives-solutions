#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int primeDivisorCount(int n) {
    int res = 0;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            while (n % d == 0)
                n /= d;
        }
    }
    res += n > 1;
    return res;
}

vector<int> prepare() {
    vector<int> res;
    for (int i = 1; res.size() < 1000; i++)
        if (primeDivisorCount(i) >= 3)
            res.push_back(i);
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> res = prepare();

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