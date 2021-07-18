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

    bool markupEnabled = 1;

    char c;
    cin >> noskipws;
    while (cin >> c) {
        if (c != '\\') {
            cout << c;
            continue;
        }

        if (cin.peek() == '*') {
            cin >> c;
            markupEnabled ^= 1;
        } else if (!markupEnabled) {
            cout << '\\';
        } else if (cin.peek() == 's') {
            cin >> c;
            bool dot = 0;
            while (isdigit(cin.peek()) || cin.peek() == '.' && !dot) {
                cin >> c;
                dot |= c == '.';
            }
        } else {
            cin >> c;
            if (c != 'b' && c != 'i')
                cout << c;
        }
    }
}