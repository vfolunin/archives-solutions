#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s >> s;

    vector<int> res(s.size() + 1);
    for (int size = 1; size <= s.size(); size++) {
        res[size] = res[size - 1];
        for (int partSize = 1, partSum = 0; partSize <= size; partSize++) {
            partSum += s[size - partSize] - '0';
            if (partSum > partSize - partSum)
                res[size] = max(res[size], res[size - partSize] + partSize);
        }
    }

    cout << res.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}