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

    string text, word;
    cin >> text >> word;

    string letters = "aeiost";
    string digits = "431057";

    for (int from = 0; from + word.size() <= text.size(); from++) {
        int ok = 1;
        for (int i = 0; i < word.size() && ok; i++)
            ok &= text[from + i] == word[i] || letters.find(word[i]) != -1 &&
                  text[from + i] == digits[letters.find(word[i])];

        if (ok) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}