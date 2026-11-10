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

    string abbr;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;

        abbr += s[0];
    }

    cout << (abbr == "ICPC");
}