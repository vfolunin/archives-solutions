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
    getline(cin, s);

    int l, r;
    cin >> l >> r;

    s.erase(s.begin() + l, s.begin() + r + 1);

    cout << s;
}