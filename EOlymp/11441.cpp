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

    int p1 = s.find('-');
    int p2 = s.find('_');

    cout << s.substr(0, p1) << "\n";
    cout << s.substr(p1 + 1, p2 - p1 - 1) << "\n";
    cout << s.substr(p2 + 1);
}