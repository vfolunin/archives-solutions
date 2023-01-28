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

    string s;
    cin >> s;

    for (int i = 0; i < s.size() / 2; i++) {
        cout << s[i];
        if (s.size() % 2 || i + 1 < s.size() / 2)
            cout << "(";
    }
    for (int i = s.size() / 2; i < s.size(); i++) {
        if (i > s.size() / 2)
            cout << ")";
        cout << s[i];
    }
}