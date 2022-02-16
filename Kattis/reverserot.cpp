#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int shift;
    string text;
    if (!(cin >> shift >> text))
        return 0;

    reverse(text.begin(), text.end());
    static string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

    for (char letter : text)
        cout << letters[(letters.find(letter) + shift) % letters.size()];
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}