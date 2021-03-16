#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(10001);
    for (int sum = 1; sum < res.size(); sum++) {
        res[sum] = sum;
        for (int i = 2; i * i <= sum; i++)
            res[sum] = min(res[sum], 1 + res[sum - i * i]);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}