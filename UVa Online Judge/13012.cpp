#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int type;
    if (!(cin >> type))
        return 0;

    int res = 0;
    for (int i = 0; i < 5; i++) {
        int guess;
        cin >> guess;
        res += guess == type;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}