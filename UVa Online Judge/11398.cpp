#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> tokens;
    while (1) {
        string s;
        cin >> s;

        if (s[0] != '0')
            break;

        tokens.push_back(s.size());
    }

    if (tokens.empty())
        return 0;

    long long res = 0, bit = 0;
    for (int t : tokens) {
        if (t <= 2)
            bit = t % 2;
        else
            for (int i = 2; i < t; i++)
                res = res * 2 + bit;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}