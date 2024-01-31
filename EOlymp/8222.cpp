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

    int len = r - l + 1;

    cout << len << "\n" << s.substr(l - 1, len);
}