#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<char> buildTable(string &line) {
    static string text = "the quick brown fox jumps over the lazy dog";

    if (line.size() != text.size())
        return {};

    vector<char> table(26, '?');
    for (int i = 0; i < line.size(); i++) {
        if (((bool)islower(line[i])) != ((bool)islower(text[i])))
            return {};
        if (islower(line[i])) {
            if (table[line[i] - 'a'] != '?' && table[line[i] - 'a'] != text[i])
                return {};
            table[line[i] - 'a'] = text[i];
        }
    }
    
    return table;
}

void solve(int test) {
    vector<string> lines;
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        lines.push_back(line);
    }

    vector<char> table;
    for (string &line : lines) {
        table = buildTable(line);
        if (!table.empty())
            break;
    }

    if (test)
        cout << "\n";
    if (table.empty()) {
        cout << "No solution.\n";
    } else {
        for (string &line : lines) {
            for (char &c : line)
                if (islower(c))
                    c = table[c - 'a'];
            cout << line << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    string line;
    getline(cin, line);
    getline(cin, line);

    for (int i = 0; i < n; i++)
        solve(i);
}