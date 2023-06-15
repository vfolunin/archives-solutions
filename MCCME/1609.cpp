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

    string s;
    getline(cin, s);

    int len = 0, maxLen = 0;
    for (char c : s) {
        if (isalpha(c))
            len++;
        else
            len = 0;
        maxLen = max(maxLen, len);
    }

    for (char &c : s) {
        if (islower(c))
            c = (c - 'a' + maxLen) % 26 + 'a';
        else if (isupper(c))
            c = (c - 'A' + maxLen) % 26 + 'A';
    }

    cout << s;
}