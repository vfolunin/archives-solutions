#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            s[i] = '_';
        else if (!i || s[i - 1] == '_')
            s[i] = toupper(s[i]);
    }

    cout << "Case#" << test << ": " << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;
    cin.ignore();

    for (int test = 1; test <= testCount; test++)
        solve(test);
}