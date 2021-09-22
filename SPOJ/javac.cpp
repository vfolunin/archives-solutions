#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getType(string &s) {
    bool java = 1, cpp = 1;

    for (int i = 0; i < s.size(); i++) {
        java &= islower(s[i]) || isupper(s[i]) && i;
        cpp &= islower(s[i]) || (s[i] == '_' && i && i + 1 < s.size() && islower(s[i + 1]));
    }

    if (!java && !cpp)
        return 0;
    else if (java)
        return 1;
    else
        return 2;
}

string toJava(string &s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_')
            res += toupper(s[++i]);
        else
            res += s[i];
    }
    return res;
}

string toCpp(string &s) {
    string res;
    for (char c : s) {
        if (isupper(c))
            res += '_';
        res += tolower(c);
    }
    return res;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int type = getType(s);

    if (type == 0)
        cout << "Error!\n";
    else if (type == 1)
        cout << toCpp(s) << "\n";
    else
        cout << toJava(s) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}