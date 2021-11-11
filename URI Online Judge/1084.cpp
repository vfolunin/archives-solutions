#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int initLength, deletions;
    cin >> initLength >> deletions;

    if (!initLength && !deletions)
        return 0;

    string init, res;
    cin >> init;

    for (char c : init) {
        while (!res.empty() && res.back() < c && deletions) {
            res.pop_back();
            deletions--;
        }
        res += c;
    }

    while (deletions) {
        res.pop_back();
        deletions--;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}