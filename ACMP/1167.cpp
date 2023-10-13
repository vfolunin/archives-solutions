#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int eval(string &s, int &i) {
    if (isdigit(s[i]))
        return s[i++] - '0';

    char op = s[i];
    i += 2;
    int a = eval(s, i);
    i++;
    int b = eval(s, i);
    i++;
    return op == 'm' ? min(a, b) : max(a, b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int i = 0;
    cout << eval(s, i);
}