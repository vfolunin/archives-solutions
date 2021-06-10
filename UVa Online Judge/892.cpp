#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string word;
    bool hyphen = 0;

    while (1) {
        string line;
        getline(cin, line);

        if (line == "#")
            break;

        for (char c : line) {
            if (isalpha(c)) {
                word += c;
            } else if (c == ' ') {
                if (hyphen) {
                    cout << "\n" << word << "\n" << c;
                    hyphen = 0;
                } else {
                    cout << word << c;
                }
                word = "";
            }
        }

        hyphen = (line.size() > 1 && isalpha(line[line.size() - 2]) && line[line.size() - 1] == '-');
        if (!hyphen) {
            cout << word << "\n";
            word = "";
        }
    }
}