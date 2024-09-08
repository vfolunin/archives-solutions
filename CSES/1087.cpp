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

    unordered_set<char> chars;
    string res;

    for (char c : s) {
        chars.insert(c);
        if (chars.size() == 4) {
            chars.clear();
            res += c;
        }
    }

    for (char c : { 'A', 'C', 'G', 'T' }) {
        if (!chars.count(c)) {
            res += c;
            break;
        }
    }

    cout << res;
}