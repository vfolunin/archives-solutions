#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    static string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
    static vector<string> codes = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----"
    };

    string morse;
    vector<int> lengths;
    for (char c : line) {
        string &code = codes[letters.find(c)];
        morse += code;
        lengths.push_back(code.size());
    }

    reverse(lengths.begin(), lengths.end());

    for (int i = 0, from = 0; i < lengths.size(); i++) {
        string code = morse.substr(from, lengths[i]);
        cout << letters[find(codes.begin(), codes.end(), code) - codes.begin()];
        from += lengths[i];
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}