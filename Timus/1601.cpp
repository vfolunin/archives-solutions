#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char c;
    bool first = 1;
    while (cin >> noskipws >> c) {
        if (isalpha(c) && first) {
            c = toupper(c);
            first = 0;
        } else {
            c = tolower(c);
            if (c == '.' || c == '!' || c == '?')
                first = 1;
        }
        cout << c;
    }
}