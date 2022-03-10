#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toggleCase(string s) {
    for (char &c : s)
        c = islower(c) ? toupper(c) : tolower(c);
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> b >> a;

    if (a == b ||
        a.size() + 1 == b.size() && a == b.substr(0, a.size()) && isdigit(b.back()) ||
        a.size() + 1 == b.size() && a == b.substr(1) && isdigit(b.front()) ||
        a == toggleCase(b))
        cout << "Yes";
    else
        cout << "No";
}