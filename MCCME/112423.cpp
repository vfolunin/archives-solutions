#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    unordered_set<int> digits;
    for (char c : s)
        if (isdigit(c))
            digits.insert(c - '0');

    bool found = 0;
    for (int i = 1; i <= 9; i++) {
        if (!digits.count(i)) {
            found = 1;
            cout << i;
        }
    }

    if (!found)
        cout << 0;
}