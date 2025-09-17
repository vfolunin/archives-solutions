#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int shift;
    cin >> shift;

    string s;
    getline(cin, s);

    for (char &c : s) {
        if (!isupper(c))
            continue;

        c = (c - 'A' + shift) % 26 + 'A';
    }

    cout << "#" << test << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}