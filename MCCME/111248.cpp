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

    string s, code;
    getline(cin, s);
    cin >> code;

    for (char &c : s)
        if (isalpha(c))
            c = code[c - 'A'];

    cout << s;
}