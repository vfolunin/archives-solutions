#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> splitCsv(string &line) {
    vector<string> tokens;
    string token;
    enum { STRING, QUOTE } mode = STRING;

    for (int i = 0; i < line.size(); i++) {
        if (mode == STRING) {
            if (line[i] == ',') {
                tokens.push_back(token);
                token.clear();
            } else if (line[i] == '"' && token.empty()) {
                mode = QUOTE;
            } else {
                token += line[i];
            }
        } else {
            if (line[i] == '"') {
                if (i + 1 < line.size() && line[i + 1] == '"') {
                    token += "\"";
                    i++;
                } else {
                    mode = STRING;
                }
            } else {
                token += line[i];
            }
        }
    }
    tokens.push_back(token);

    return tokens;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> width;
    vector<vector<string>> table;

    for (string line; getline(cin, line); ) {
        table.push_back(splitCsv(line));
        if (width.size() < table.back().size())
            width.resize(table.back().size());
        for (int i = 0; i < table.back().size(); i++)
            width[i] = max<int>(width[i], table.back()[i].size());
    }

    for (int y = 0; y < table.size(); y++) {
        for (int x = 0; x < width.size(); x++) {
            if (x)
                cout << "|";
            if (x < table[y].size())
                cout << table[y][x] << string(width[x] - table[y][x].size(), ' ');
            else
                cout << string(width[x], ' ');
        }
        cout << "\n";
    }
}