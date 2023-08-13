#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isCpp(string &s) {
    if (s.front() == '_' || s.back() == '_' || s.find("__") != -1)
        return 0;
    for (char c : s)
        if (!islower(c) && c != '_')
            return 0;
    return 1;
}

bool isJava(string &s) {
    if (!islower(s.front()))
        return 0;
    for (char c : s)
        if (!isalpha(c))
            return 0;
    return 1;
}

void toCpp(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i]))
            cout << s[i];
        else
            cout << "_" << (char)tolower(s[i]);
    }
}

void toJava(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '_')
            cout << s[i];
        else
            cout << (char)toupper(s[++i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (isCpp(s))
        toJava(s);
    else if (isJava(s))
        toCpp(s);
    else
        cout << "Error!";
}