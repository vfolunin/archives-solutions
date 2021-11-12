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

    int dot = s.find('.');
    string a = s.substr(0, dot);
    string b = s.substr(dot + 1);

    while (b.size() > 1 && b[0] == '0')
        b.erase(0, 1);

    cout << b << "." << a << "\n";
}