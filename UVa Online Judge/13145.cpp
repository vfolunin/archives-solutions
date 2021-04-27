#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int shift;
    cin >> shift;

    if (!shift)
        return 0;

    string text;
    cin.ignore();
    getline(cin, text);

    for (char &c : text) {
        if (isupper(c))
            c = ((c - 'A' + shift) % 26 + 26) % 26 + 'A';
        else if (islower(c))
            c = ((c - 'a' + shift) % 26 + 26) % 26 + 'a';
    }

    cout << text << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}