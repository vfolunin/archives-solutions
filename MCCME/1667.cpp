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

    string word;

    for (char c; cin >> noskipws >> c; ) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                cout << word;
                word.clear();
            }
            cout << c;
        }
    }

    if (!word.empty()) {
        reverse(word.begin(), word.end());
        cout << word;
    }
}