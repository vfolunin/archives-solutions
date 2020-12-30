#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;
    if (s == "#")
        return 0;

    if (next_permutation(s.begin(), s.end()))
        cout << s << "\n";
    else
        cout << "No Successor\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}