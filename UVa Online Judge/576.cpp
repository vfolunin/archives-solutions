#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    getline(cin, line);

    if (line == "e/o/i")
        return 0;

    line += "/";

    static const string VOWELS = "aeiouy";
    bool in = 0;
    int row = 1, syllables = 0;

    for (char c : line) {
        if (VOWELS.find(c) != -1) {
            if (!in) {
                in = 1;
                syllables++;
            }
        } else {
            in = 0;
            if (c == '/') {
                if (row == 2 && syllables != 7 || row != 2 && syllables != 5) {
                    cout << row << "\n";
                    return 1;
                }
                syllables = 0;
                row++;
            }
        }
    }

    cout << "Y\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}