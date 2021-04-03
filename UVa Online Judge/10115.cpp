#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int replaceCount;
    cin >> replaceCount;
    cin.ignore();

    if (!replaceCount)
        return 0;

    vector<pair<string, string>> replaces(replaceCount);
    for (auto &[a, b] : replaces) {
        getline(cin, a);
        getline(cin, b);
    }
    
    string text;
    getline(cin, text);

    for (auto &[a, b] : replaces) {
        while (1) {
            auto pos = text.find(a);
            if (pos == -1)
                break;
            text.replace(pos, a.size(), b);
        }
    }

    cout << text << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}