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

    bool in = 0;
    char c;

    cin >> noskipws;
    while (cin >> c) {
        if (c != '"') {
            cout << c;
        } else if (!in) {
            in = 1;
            cout << "``";
        } else {
            in = 0;
            cout << "''";
        }
    }
}