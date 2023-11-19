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
    int l, r;
    cin >> s >> l >> r;

    reverse(s.begin() + l - 1, s.begin() + r);

    cout << s;
}