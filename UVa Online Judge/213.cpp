#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string letters;
    if (!getline(cin, letters))
        return 0;

    while (1) {
        int length = 0;
        char c;
        for (int i = 0; i < 3; i++) {
            cin >> c;
            length = length * 2 + c - '0';
        }

        if (!length)
            break;

        int offset = 0;
        for (int i = 1; i < length; i++)
            offset += (1 << i) - 1;

        while (1) {
            int code = 0;
            for (int i = 0; i < length; i++) {
                cin >> c;
                code = code * 2 + c - '0';
            }

            if (code == (1 << length) - 1)
                break;

            cout << letters[offset + code];
        }
    }

    cin.ignore();
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}