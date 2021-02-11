#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string readTo(char symbol) {
    string res;
    cin >> noskipws;
    char c;
    while (cin >> c) {
        if (c == symbol)
            break;
        res += c;
    }
    return res;
}

void solve() {
    string a = readTo('<');
    string b = readTo('>');
    string c = readTo('<');
    string d = readTo('>');
    string e = readTo('\n');
    string f = readTo('\n');
    f = f.substr(0, f.size() - 3);
    cout << a << b << c << d << e << "\n";
    cout << f << d << c << b << e << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}