#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isConsonant(char c) {
    static string vowels = "aeiou";
    return vowels.find(tolower(c)) == -1;
}

void solve() {
    string surname;
    cin >> surname;

    int row = 0;
    for (char c : surname) {
        if (isConsonant(c))
            row++;
        else
            row = 0;

        if (row >= 3) {
            cout << surname << " nao eh facil\n";
            return;
        }
    }

    cout << surname << " eh facil\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}