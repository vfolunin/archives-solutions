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

    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);

    cout << a << b << c << "\n";
    cout << b << c << a << "\n";
    cout << c << a << b << "\n";
    cout << a.substr(0, 10) << b.substr(0, 10) << c.substr(0, 10) << "\n";
}