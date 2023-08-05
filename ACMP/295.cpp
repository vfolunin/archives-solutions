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

    string text, pattern;
    cin >> text >> pattern;

    for (int i = 0; i < 26; i++) {
        if (text.find(pattern) != -1) {
            cout << text;
            return 0;
        }

        for (char &c : text)
            c = (c - 'A' + 25) % 26 + 'A';
    }

    cout << "IMPOSSIBLE";
}