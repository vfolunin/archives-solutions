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

    for (char &c : s)
        if (c == 'a' || c == 'b')
            c = 'a' + 'b' - c;

    cout << s;
}