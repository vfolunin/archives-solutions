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

    string word, text;
    cin >> word >> text;

    int from = 0;
    while (!word.empty()) {
        int pos = text.find_first_of(word, from);
        if (pos == -1 || text[pos] != word[0]) {
            cout << "FAIL";
            return 0;
        }
        from = pos + 1;
        word = word.substr(1);
    }

    cout << "PASS";
}