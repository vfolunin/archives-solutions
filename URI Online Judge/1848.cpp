#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int res = 0;

    while (1) {
        string line;
        getline(cin, line);

        if (line == "caw caw")
            break;

        for (int i = 0; i < 3; i++)
            if (line[i] == '*')
                res += 1 << (2 - i);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 3; i++)
        solve();
}