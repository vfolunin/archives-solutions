#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> res;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x)
            res.push_back(x);
    }
        
    if (res.empty()) {
        cout << "0\n";
    } else {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}