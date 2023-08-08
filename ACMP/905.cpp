#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string decode(string line, string &mapping) {
    for (char &c : line)
        if (islower(c))
            c = mapping[c - 'a'];
    return line;
}

string getMapping(string &line) {
    static string key = "the quick brown fox jumps over the lazy dog";
    if (line.size() != key.size())
        return "";

    string mapping(26, ' ');
    for (int i = 0; i < line.size(); i++) {
        if ((line[i] == ' ') ^ (key[i] == ' '))
            return "";
        else if (islower(line[i]))
            mapping[line[i] - 'a'] = key[i];
    }

    return decode(line, mapping) == key ? mapping : "";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lineCount;
    cin >> lineCount;
    cin.ignore();

    vector<string> lines(lineCount);
    for (string &line : lines)
        getline(cin, line);

    string mapping;
    for (int i = 0; i < lines.size() && mapping.empty(); i++)
        mapping = getMapping(lines[i]);

    if (!mapping.empty()) {
        for (string &line : lines)
            cout << decode(line, mapping) << "\n";
    } else {
        cout << "No solution";
    }
}