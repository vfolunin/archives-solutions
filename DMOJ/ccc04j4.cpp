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

    string key, text;
    getline(cin, key);
    getline(cin, text);

    int i = 0;
    for (char c : text)
        if (isupper(c))
            cout << (char)((c - 'A' + key[i++ % key.size()] - 'A') % 26 + 'A');
}