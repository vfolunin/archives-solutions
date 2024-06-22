#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> rec(long long sum) {
    if (!sum)
        return {};
    if (sum % 2) {
        long long value = 1;
        while (value * 3 <= sum)
            value *= 3;
        vector<long long> res = rec(sum - value);
        res.push_back(value);
        return res;
    } else {
        vector<long long> res = rec(sum / 2);
        for (long long &value : res)
            value *= 2;
        return res;
    }
}

void solve() {
    long long sum;
    cin >> sum;

    vector<long long> res = rec(sum);

    cout << res.size() << "\n";
    for (long long value : res)
        cout << value << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}