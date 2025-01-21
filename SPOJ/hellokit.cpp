#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    int count;
    if (!(cin >> s >> count))
        return 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < count; j++)
            cout << s;
        cout << "\n";

        rotate(s.begin(), s.begin() + 1, s.end());
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}