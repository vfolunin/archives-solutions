#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {   
    int digitCount;
    char type;
    if (!(cin >> digitCount >> type))
        return 0;

    static vector<string> braille = {
        ".* *. *. ** ** *. ** ** *. .* ",
        "** .. *. .. .* .* *. ** ** *. ",
        ".. .. .. .. .. .. .. .. .. .. "
    };

    if (type == 'S') {
        string line;
        cin >> line;

        for (char row = 0; row < 3; row++) {
            for (int i = 0; i < line.size(); i++) {
                for (char col = 0; col < 2; col++)
                    cout << braille[row][3 * (line[i] - '0') + col];
                cout << (i + 1 < line.size() ? ' ' : '\n');
            }
        }
    } else {
        cin.ignore();

        vector<string> lines(3);
        for (string &line : lines)
            getline(cin, line);

        for (int col = 0; col < lines[0].size(); col += 3) {
            for (int d = 0; d < 10; d++) {
                if (lines[0][col] == braille[0][d * 3] &&
                    lines[0][col + 1] == braille[0][d * 3 + 1] &&
                    lines[1][col] == braille[1][d * 3] &&
                    lines[1][col + 1] == braille[1][d * 3 + 1]) {
                    cout << d;
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}