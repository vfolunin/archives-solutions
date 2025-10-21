#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string prevDir;
    while (1) {
        string s;
        cin >> s;

        if (s == "99999")
            break;

        string dir = prevDir;
        if ((s[0] + s[1]) % 2)
            dir = "left";
        else if (s[0] + s[1] != '0' + '0')
            dir = "right";

        cout << dir << " " << stoi(s.substr(2)) << "\n";

        prevDir = dir;
    }
}