#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string makeTable() {
    string key;
    getline(cin, key);

    string table;
    for (char c : key)
        if (isalpha(c) && table.find(c) == -1)
            table += c;

    for (char c = 'a'; c <= 'z'; c++)
        if (c != 'q' && table.find(c) == -1)
            table += c;

    return table;
}

void solve() {
    string table = makeTable();

    string text;
    getline(cin, text);
    text.erase(remove(text.begin(), text.end(), ' '), text.end());

    string code;
    for (int i = 0; i < text.size(); i += 2) {
        if (i + 1 == text.size() || text[i] == text[i + 1])
            text.insert(i + 1, 1, 'x');

        int pos1 = table.find(text[i]), y1 = pos1 / 5, x1 = pos1 % 5;
        int pos2 = table.find(text[i + 1]), y2 = pos2 / 5, x2 = pos2 % 5;

        if (y1 == y2) {
            code += table[y1 * 5 + (x1 + 1) % 5];
            code += table[y2 * 5 + (x2 + 1) % 5];
        } else if (x1 == x2) {
            code += table[(y1 + 1) % 5 * 5 + x1];
            code += table[(y2 + 1) % 5 * 5 + x2];
        } else {
            code += table[y1 * 5 + x2];
            code += table[y2 * 5 + x1];
        }
    }

    for (char c : code)
        cout << (char)toupper(c);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}