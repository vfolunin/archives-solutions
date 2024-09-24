#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> read() {
    string line;
    getline(cin, line);
    line = line.substr(7);

    vector<string> words;
    string word;

    for (char c : line) {
        if (c != ',') {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(8, string(8, ' '));

    for (string &cell : read()) {
        if (cell.size() == 2)
            cell = "P" + cell;
        a['8' - cell[2]][cell[1] - 'a'] = cell[0];
    }

    for (string &cell : read()) {
        if (cell.size() == 2)
            cell = "P" + cell;
        a['8' - cell[2]][cell[1] - 'a'] = tolower(cell[0]);
    }

    cout << "+";
    for (int x = 0; x < 8; x++)
        cout << "---+";
    cout << "\n";

    for (int y = 0; y < 8; y++) {
        cout << "|";
        for (int x = 0; x < 8; x++) {
            cout << ((y + x) % 2 ? ":" : ".");
            if (a[y][x] != ' ')
                cout << a[y][x];
            else
                cout << ((y + x) % 2 ? ":" : ".");
            cout << ((y + x) % 2 ? ":|" : ".|");
        }
        cout << "\n";

        cout << "+";
        for (int x = 0; x < 8; x++)
            cout << "---+";
        cout << "\n";
    }
}