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

    string s;
    cin >> s;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    string palindrome;
    char oddChar = '?';

    for (auto &[c, k] : count) {
        if (k % 2) {
            if (oddChar == '?') {
                oddChar = c;
            } else {
                cout << "NO SOLUTION";
                return 0;
            }
        }

        palindrome += string(k / 2, c);
    }

    cout << palindrome;
    if (oddChar != '?')
        cout << oddChar;
    reverse(palindrome.begin(), palindrome.end());
    cout << palindrome;
}