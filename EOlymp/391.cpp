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

    string s;
    cin >> s;

    vector<string> a = {
        "    _     _  _     _  _  _  _  _ ",
        " _ | |  | _| _||_||_ |_   ||_||_|",
        "   |_|  ||_  _|  | _||_|  ||_| _|"
    };

    for (string &row : a) {
        for (char c : s)
            cout << row.substr(c == '-' ? 0 : (c - '0' + 1) * 3, 3);
        cout << "\n";
    }
}