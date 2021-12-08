#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char decode(const string &code) {
    static vector<string> morse = {
        "=.===", "===.=.=.=", "===.=.===.=", "===.=.=", "=", "=.=.===.=",
        "===.===.=", "=.=.=.=", "=.=", "=.===.===.===", "===.=.===",
        "=.===.=.=", "===.===", "===.=", "===.===.===", "=.===.===.=",
        "===.===.=.===", "=.===.=", "=.=.=", "===", "=.=.===",
        "=.=.=.===", "=.===.===", "===.=.=.===", "===.=.===.===", "===.===.=.="
    };
    return find(morse.begin(), morse.end(), code) - morse.begin() + 'a';
}

void solve() {
    string code;
    cin >> code;

    while (1) {
        int spacePos = code.find("...");
        cout << (spacePos ? decode(code.substr(0, spacePos)) : ' ');
        if (spacePos == -1)
            break;
        code = code.substr(spacePos + (spacePos ? 3 : 4));
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}