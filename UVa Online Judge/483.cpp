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
    char c;

    cin >> noskipws;
    while (cin >> c) {
        if (isgraph(c)) {
            word += c;
        } else {
            reverse(word.begin(), word.end());
            cout << word << c;
            word.clear();
        }
    }

    reverse(word.begin(), word.end());
    cout << word;
}