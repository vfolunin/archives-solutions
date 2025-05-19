#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(string &s, int targetCount) {
    string word = "PANDA";
    int i = 0, count = 0;
    for (char c : s) {
        if (i < word.size() && c == word[i]) {
            count++;
            if (count == targetCount) {
                i++;
                count = 0;
            }
        }
    }
    return i == word.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int l = 0, r = 1;
    while (can(s, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(s, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}