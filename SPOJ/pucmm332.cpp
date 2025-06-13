#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    int shift;
    cin >> s >> shift;

    for (char &c : s)
        c = (c - 'A' + 26 - shift % 26) % 26 + 'A';

    cout << "Test Case #" << test << ": " << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}