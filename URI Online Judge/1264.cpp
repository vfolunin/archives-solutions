#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int sum = 0, base = 2;
    for (char c : s) {
        if (isdigit(c))
            c -= '0';
        else if (isupper(c))
            c = c - 'A' + 10;
        else if (islower(c))
            c = c - 'a' + 36;
        else
            c = 0;

        sum += c;
        base = max(base, c + 1);
    }

    while (base <= 62 && sum % (base - 1))
        base++;

    if (base <= 62)
        cout << base << "\n";
    else
        cout << "such number is impossible!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}