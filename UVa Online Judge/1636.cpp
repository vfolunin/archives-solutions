#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int shootEmpty = 0, shootFull = 0, rotateEmpty = 0, rotateFull = 0;
    for (int i = 0; i < s.size(); i++) {
        shootEmpty += (s[i] == '0' && s[(i + 1) % s.size()] == '0');
        shootFull += (s[i] == '0' && s[(i + 1) % s.size()] == '1');
        rotateEmpty += s[i] == '0';
        rotateFull += s[i] == '1';
    }

    if (shootEmpty * rotateFull > rotateEmpty * shootFull)
        cout << "SHOOT\n";
    else if (shootEmpty * rotateFull < rotateEmpty * shootFull)
        cout << "ROTATE\n";
    else
        cout << "EQUAL\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}