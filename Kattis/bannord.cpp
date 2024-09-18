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

    string letters;
    cin >> letters;

    bool first = 1;
    for (string word; cin >> word; ) {
        bool found = 0;
        for (char letter : letters)
            found |= word.find(letter) != -1;

        if (first)
            first = 0;
        else
            cout << " ";
        cout << (found ? string(word.size(), '*') : word);
    }
}