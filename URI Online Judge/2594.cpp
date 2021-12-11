#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

void solve() {
    string text, word;
    getline(cin, text);
    getline(cin, word);

    text = " " + text + " ";
    word = " " + word + " ";
    vector<int> p = prefixFunction(word + "#" + text);
    vector<int> positions;

    for (int i = word.size() + 1; i < p.size(); i++)
        if (p[i] == word.size())
            positions.push_back(i - 2 * word.size());

    if (!positions.empty()) {
        for (int i = 0; i < positions.size(); i++)
            cout << positions[i] << (i + 1 < positions.size() ? " " : "\n");
    } else {
        cout << "-1\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}