#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    int row = 1, res = 1;
    const int MOD = 1e9 + 7;
    for (int i = 1; i < a.size(); i++) {
        row = (a[i - 1][0] == a[i][0] ? row + 1 : 1);
        res = (res + row) % MOD;
    }

    cout << res;
}