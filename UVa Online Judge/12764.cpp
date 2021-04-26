#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string code;
    cin >> code;

    static vector<string> frames = {
        "\\ /  o          _o_ \\o/ \\o_ \\o/      o  ",
        " |  /|\\          |   |  \\|  \\|/  __o( ) ",
        "/o\\ / \\ __\\o\\_\\o/ \\ / \\  |      /  |/ \\ "
    };

    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < code.size(); i++) {
            for (int col = 0; col < 4; col++)
                cout << frames[row][(code[i] - '0') * 4 + col];
            cout << (i + 1 < code.size() ? " " : "\n");
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}