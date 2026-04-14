#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string read() {
    string s;
    cin >> s;

    for (char &c : s)
        c = tolower(c);

    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a = read();
    string b = read();

    if (a < b)
        cout << -1;
    else if (a == b)
        cout << 0;
    else
        cout << 1;
}