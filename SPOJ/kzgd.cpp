#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

vector<int> prepare() {
    vector<int> res;
    for (int i = 1; res.size() < 500; i++)
        if (ones(i) % 2)
            res.push_back(i);
    return res;
}

void solve() {
    int index;
    cin >> index;

    static vector<int> res = prepare();

    cout << res[index - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}