#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int lineCount;
    cin >> lineCount;

    if (!lineCount)
        return 0;

    int y = 0, x = 0;
    vector<string> screen(10, string(10, ' '));
    enum {INSERT, OVERWRITE} mode = OVERWRITE;

    string line;
    getline(cin, line);
    for (int i = 0; i < lineCount; i++) {
        getline(cin, line);
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '^') {
                j++;
                if (line[j] == 'b') {
                    x = 0;
                } else if (line[j] == 'c') {
                    screen.assign(10, string(10, ' '));
                } else if (line[j] == 'd') {
                    y = min(y + 1, 9);
                } else if (line[j] == 'e') {
                    fill(screen[y].begin() + x, screen[y].end(), ' ');
                } else if (line[j] == 'h') {
                    y = x = 0;
                } else if (line[j] == 'i') {
                    mode = INSERT;
                } else if (line[j] == 'l') {
                    x = max(x - 1, 0);
                } else if (line[j] == 'o') {
                    mode = OVERWRITE;
                } else if (line[j] == 'r') {
                    x = min(x + 1, 9);
                } else if (line[j] == 'u') {
                    y = max(y - 1, 0);
                } else if (line[j] == '^') {
                    if (mode == INSERT)
                        rotate(screen[y].begin() + x, screen[y].end() - 1, screen[y].end());
                    screen[y][x] = '^';
                    x = min(x + 1, 9);
                } else {
                    y = line[j++] - '0';
                    x = line[j] - '0';
                }
            } else {
                if (mode == INSERT)
                    rotate(screen[y].begin() + x, screen[y].end() - 1, screen[y].end());
                screen[y][x] = line[j];
                x = min(x + 1, 9);
            }
        }
    }

    cout << "Case " << test << "\n";
    cout << "+" << string(10, '-') << "+\n";
    for (string &row : screen)
        cout << "|" << row << "|\n";
    cout << "+" << string(10, '-') << "+\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}