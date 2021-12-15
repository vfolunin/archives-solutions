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

    int runeCount, minSum;
    cin >> runeCount >> minSum;

    map<char, int> runeValue;
    for (int i = 0; i < runeCount; i++) {
        char rune;
        cin >> rune >> runeValue[rune];
    }

    int takenRuneCount;
    cin >> takenRuneCount;

    int sum = 0;
    for (int i = 0; i < takenRuneCount; i++) {
        char rune;
        cin >> rune;
        sum += runeValue[rune];
    }

    cout << sum << "\n";
    if (sum >= minSum)
        cout << "You shall pass!\n";
    else
        cout << "My precioooous\n";
}