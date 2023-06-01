#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    for (char &c : s) {
        if (islower(c))
            c = (c - 'a' + 1) % 26 + 'a';
        else if (isupper(c))
            c = (c - 'A' + 1) % 26 + 'A';
        else if (isdigit(c))
            c = (c - '0' + 9) % 10 + '0';
    }

    cout << s;
}