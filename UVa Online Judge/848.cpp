#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> read() {
    vector<string> parts;
    string part;

    char c;
    cin >> noskipws;
    while (cin >> c) {
        if (c == '\n') {
            if (!part.empty()) {
                parts.push_back(part);
                part.clear();
            }
            parts.push_back("\n");
        } else if (c == ' ') {
            if (part.empty() || part.back() == ' ') {
                part.push_back(c);
            } else {
                parts.push_back(part);
                part = " ";
            }
        } else {
            if (part.empty() || part.back() != ' ') {
                part.push_back(c);
            } else {
                parts.push_back(part);
                part = string(1, c);
            }
        }
    }

    if (!part.empty())
        parts.push_back(part);

    return parts;
}

vector<string> removeEndls(vector<string> &partsWithEndls) {
    vector<string> partsWithSpaces;
    for (int i = 0; i < partsWithEndls.size(); i++) {
        if (partsWithEndls[i] != "\n" ||
            (i - 1 >= 0 && partsWithEndls[i - 1] == "\n") ||
            (i + 1 < partsWithEndls.size() && !isalpha(partsWithEndls[i + 1][0])))
            partsWithSpaces.push_back(partsWithEndls[i]);
        else
            partsWithSpaces.push_back(" ");
    }

    vector<string> parts = { partsWithSpaces[0] };
    for (int i = 1; i < partsWithSpaces.size(); i++) {
        if (partsWithSpaces[i - 1][0] == ' ' && partsWithSpaces[i][0] == ' ')
            parts.back().push_back(' ');
        else
            parts.push_back(partsWithSpaces[i]);
    }

    return parts;
}

vector<string> makeLines(vector<string> &parts) {
    vector<string> lines;
    string line;

    for (string &part : parts) {
        if (part == "\n") {
            lines.push_back(line);
            line.clear();
        } else if (part[0] != ' ' && line.size() + part.size() > 72) {
            lines.push_back(line);
            line = part;
        } else {
            line += part;
        }
    }
    if (!line.empty()) 
        lines.push_back(line);

    return lines;
}

void printLines(vector<string> &lines) {
    for (string &line : lines) {
        while (!line.empty() && line.back() == ' ')
            line.pop_back();
        cout << line << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> parts = read();
    parts = removeEndls(parts);
    vector<string> lines = makeLines(parts);
    printLines(lines);
}