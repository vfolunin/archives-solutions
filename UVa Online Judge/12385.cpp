#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int seqSize;
    cin >> seqSize;

    vector<int> seq(seqSize);
    for (int &x : seq)
        cin >> x;

    int res = 0;
    set<int> seen;
    for (int l = 0, r = 0; r < seqSize; r++) {
        if (seen.count(seq[r])) {
            res++;
            while (l < r) {
                seen.erase(seq[l]);
                l++;
            }
        }
        seen.insert(seq[r]);
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