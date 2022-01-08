#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    string res, f = "bfjpsvxz";
    for (char &c : line) {
        if (f.find(tolower(c)) != -1) {
            if (res.empty() || tolower(res.back()) != 'f')
                res += (islower(c) ? 'f' : 'F');
        } else {
            res += c;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}