#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1e7 + 1, 1);
    double sum = 0;
    for (int i = 1; i < res.size(); i++) {
        sum += log10(i);
        res[i] += sum;
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