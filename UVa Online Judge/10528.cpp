#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

bool solve() {
    string line;
    getline(cin, line);

    if (line == "END")
        return 0;

    vector<string> tune = split(line);
    static vector<string> notes = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    vector<string> res;

    for (int i = 0; i < notes.size(); i++) {
        set<string> scale;
        for (int d : {0, 2, 4, 5, 7, 9, 11})
            scale.insert(notes[(i + d) % notes.size()]);

        bool ok = 1;
        for (string &note : tune)
            ok &= scale.count(note);

        if (ok)
            res.push_back(notes[i]);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? " " : "");
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}