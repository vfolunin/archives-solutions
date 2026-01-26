#include <iostream>
#include <sstream>
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

    if (int i = s.find('('); i != -1) {
        string period = s.substr(i + 1, s.size() - i - 2);
        s.resize(i);
        while (s.size() < 60)
            s += period;
    }

    stringstream ss(s);

    double whole = 0;
    for (char c; ss >> c; ) {
        if (c == '.')
            break;
        whole = whole * 2 + c - '0';
    }

    double frac = 0, value = 0.5;
    for (char c; ss >> c; value /= 2) {
        if (c == '1')
            frac += value;
        if (c == '(')
            break;
    }

    cout.precision(15);
    cout << fixed << whole + frac;
}