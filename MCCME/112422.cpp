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

    vector<int> count(26);
    for (char c; cin >> c; )
        if (isalpha(c))
            count[toupper(c) - 'A']++;

    int oddLetter = -1;
    for (int letter = 0; letter < count.size(); letter++) {
        if (count[letter] % 2) {
            if (oddLetter == -1) {
                oddLetter = letter;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    for (int letter = count.size() - 1; letter >= 0; letter--)
        cout << string(count[letter] / 2, letter + 'A');

    if (oddLetter != -1)
        cout << (char)(oddLetter + 'A');

    for (int letter = 0; letter < count.size(); letter++)
        cout << string(count[letter] / 2, letter + 'A');
}