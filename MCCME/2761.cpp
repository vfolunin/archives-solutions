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
    cin >> s;

    for (char &c : s)
        if (c > '5')
            c = (c - '0') / 2 + '0';

    for (char c : s)
        if (c % 2)
            cout << c;
}