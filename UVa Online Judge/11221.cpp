#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string line;
    getline(cin, line);

    string letters;
    for (char c : line)
        if (islower(c))
            letters += c;

    cout << "Case #" << test << ":\n";

    int size = sqrt(letters.size());
    if (size * size != letters.size()) {
        cout << "No magic :(\n";
        return;
    }

    vector<string> square(size);
    for (int i = 0; i < size; i++)
        square[i] = letters.substr(size * i, size);

    bool isPalindrome = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            isPalindrome &= square[i][j] == square[j][i];
            isPalindrome &= square[i][j] == square[size - 1 - j][size - 1 - i];
        }
    }

    if (isPalindrome)
        cout << size << "\n";
    else
        cout << "No magic :(\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}