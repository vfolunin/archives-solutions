#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int commandCount;
    cin >> commandCount;

    if (!commandCount)
        return 0;

    string bits(32, '?');

    for (int i = 0; i < commandCount; i++) {
        string command;
        int a;
        cin >> command >> a;
        a = 31 - a;

        if (command == "CLEAR") {
            bits[a] = '0';
        } else if (command == "SET") {
            bits[a] = '1';
        } else {
            int b;
            cin >> b;
            b = 31 - b;

            if (command == "OR") {
                if (bits[a] == '1' || bits[b] == '1')
                    bits[a] = '1';
                else if (bits[a] == '0' && bits[b] == '0')
                    bits[a] = '0';
                else
                    bits[a] = '?';
            } else {
                if (bits[a] == '0' || bits[b] == '0')
                    bits[a] = '0';
                else if (bits[a] == '1' && bits[b] == '1')
                    bits[a] = '1';
                else
                    bits[a] = '?';
            }
        }
    }

    cout << bits << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}