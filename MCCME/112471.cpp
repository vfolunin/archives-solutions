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

    set<char> digits;
    for (char c : s)
        if (isdigit(c))
            digits.insert(c);

    if (!digits.empty()) {
        for (char c : digits)
            cout << c;
    } else {
        cout << "NO";
    }
}