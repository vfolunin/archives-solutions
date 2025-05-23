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

    int size;
    cin >> size;

    unordered_set<string> skipped = {
        "a", "in", "is", "on", "of", "and", "the", "for"
    };

    string res;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        if (!skipped.count(s))
            res += toupper(s[0]);
    }

    cout << res;
}