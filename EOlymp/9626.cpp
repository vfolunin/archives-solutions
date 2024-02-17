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
    cin >> a >> b >> c;

    cout << (b.size() <= a.size() && a.substr(0, b.size()) == b ? "true\n" : "false\n");
    cout << (c.size() <= a.size() && a.substr(a.size() - c.size()) == c ? "true" : "false");
}