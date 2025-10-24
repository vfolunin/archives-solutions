#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, char> codes;
    for (int i = 0; i < size; i++) {
        char c;
        string code;
        cin >> c >> code;

        codes[code] = c;
    }

    string s;
    cin >> s;

    string code;
    for (char c : s) {
        code += c;
        if (codes.count(code)) {
            cout << codes[code];
            code.clear();
        }
    }
}