#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string text;
    cin >> text;

    int ruleCount;
    cin >> ruleCount;

    string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < ruleCount; i++) {
        char a, b;
        cin >> a >> b;

        for (char &c : code)
            if (c == b)
                c = a;
    }

    for (char &c : text)
        if (isupper(c))
            c = code[c - 'A'];

    cout << text << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 0; test < n; test++)
        solve();
}