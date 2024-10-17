#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void printRow(string &number, int row, int size) {
    static const string s[] = {
        " -       -   -       -   -   -   -   -  ",
        "| |   |   |   | | | |   |     | | | | | ",
        "         -   -   -   -   -       -   -  ",
        "| |   | |     |   |   | | |   | | |   | ",
        " -       -   -       -   -       -   -  "
    };

    for (int i = 0; i < number.size(); i++) {
        cout << s[row][(number[i] - '0') * 4];
        cout << string(size, s[row][(number[i] - '0') * 4 + 1]);
        cout << s[row][(number[i] - '0') * 4 + 2];
        if (i + 1 < number.size())
            cout << s[row][(number[i] - '0') * 4 + 3];
        else
            cout << "\n";
    }
}

bool solve() {
    int size;
    string number;
    cin >> size >> number;

    if (!size)
        return 0;

    printRow(number, 0, size);
    for (int i = 0; i < size; i++)
        printRow(number, 1, size);
    printRow(number, 2, size);
    for (int i = 0; i < size; i++)
        printRow(number, 3, size);
    printRow(number, 4, size);
    cout << "\n";

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}