#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    char a, b;
    cin >> s >> a >> b;

    for (char &c : s)
        c = ((c - 'A' + b - a) % 26 + 26) % 26 + 'A';

    cout << "Case " << test << "#: " << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}