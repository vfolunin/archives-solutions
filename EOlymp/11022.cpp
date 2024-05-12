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

    bool equal = 1, increasing = 1;
    for (int i = 1; i < s.size(); i++) {
        equal &= s[i - 1] == s[i];
        increasing &= s[i - 1] + 1 == s[i];
    }

    cout << (equal || increasing ? "Yes" : "No");
}