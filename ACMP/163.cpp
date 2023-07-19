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

    int a = s[0] - '0', b = s[2] - '0', c = s[4] - '0';

    if (s[0] == 'x')
        cout << (s[1] == '+' ? c - b : c + b);
    else if (s[2] == 'x')
        cout << (s[1] == '+' ? c - a : a - c);
    else
        cout << (s[1] == '+' ? a + b : a - b);
}