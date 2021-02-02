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

    string s = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";

    char c;
    cin >> noskipws;

    while (cin >> c) {
        if (isgraph(c))
            cout << s[s.find(tolower(c)) - 2];
        else
            cout << c;
    }
}