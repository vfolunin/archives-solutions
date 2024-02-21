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
    cin >> s;

    unordered_set<char> seen;
    for (char c : s) {
        if (!seen.count(c))
            cout << c;
        seen.insert(c);
    }
}