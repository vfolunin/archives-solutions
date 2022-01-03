#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        char code = 0;
        for (char c : s)
            code = code * 2 + c - '0';
        cout << code;
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}