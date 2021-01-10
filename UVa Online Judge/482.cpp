#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> pos;
    while (1) {
        pos.emplace_back();
        cin >> pos.back();
        if (cin.get() == '\n')
            break;
    }

    vector<string> val(pos.size());
    for (int i : pos)
        cin >> val[i - 1];

    if (test)
        cout << "\n";
    for (string &s : val)
        cout << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}