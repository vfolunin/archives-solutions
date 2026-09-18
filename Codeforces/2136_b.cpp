#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, windowWidth;
    string s;
    cin >> size >> windowWidth >> s;

    int curRow = 0, maxRow = 0;
    for (char c : s) {
        if (c == '1')
            curRow++;
        else
            curRow = 0;
        maxRow = max(maxRow, curRow);
    }

    if (maxRow >= windowWidth) {
        cout << "NO\n";
        return;
    }

    vector<int> res(s.size());
    int value = 1;
    for (char c : { '1', '0' })
        for (int i = 0; i < res.size(); i++)
            if (s[i] == c)
                res[i] = value++;

    cout << "YES\n";
    for (int value : res)
        cout << value << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}