#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isCol(char c) {
    return 'A' <= c && c <= 'H';
}

bool isRow(char c) {
    return '1' <= c && c <= '8';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (s.size() != 5 || !isCol(s[0]) || !isRow(s[1]) || s[2] != '-' || !isCol(s[3]) || !isRow(s[4]))
        cout << "ERROR";
    else if (abs(s[0] - s[3]) * abs(s[1] - s[4]) == 2)
        cout << "YES";
    else
        cout << "NO";
}