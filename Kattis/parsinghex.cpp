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

    string hexValue;
    char c;

    cin >> noskipws;
    while (cin >> c) {
        if (hexValue.empty() && c == '0' ||
            hexValue.size() == 1 && tolower(c) == 'x' ||
            hexValue.size() > 1 && isxdigit(c)) {
            hexValue += c;
        } else if (!hexValue.empty()) {
            cout << hexValue << " " << stoll(hexValue, 0, 16) << "\n";
            hexValue.clear();
        }
    }
}