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
        c = tolower(c);

    if (s.find("zelda") != -1)
        cout << "Link Bolado\n";
    else
        cout << "Link Tranquilo\n";
}