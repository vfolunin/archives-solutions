#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    bool upper = 1;
    for (char &c : s) {
        if (isalpha(c)) {
            c = upper ? toupper(c) : tolower(c);
            upper ^= 1;
        }
    }

    cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}