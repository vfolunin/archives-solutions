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

    int queryCount;
    cin >> queryCount;

    vector<string> symbols(5, string(5, ' '));
    for (int y = 0; y < symbols.size(); y++)
        for (int x = 0; x < symbols.size(); x++)
            cin >> symbols[y][x];

    for (int i = 0; i < queryCount; i++) {
        string code;
        cin >> code;

        for (int j = 0; j < code.size(); ) {
            if (islower(code[j])) {
                cout << code[j++];
            } else {
                cout << symbols[code[j] - 'A'][code[j + 1] - '1'];
                j += 2;
            }
        }
        cout << "\n";
    }
}