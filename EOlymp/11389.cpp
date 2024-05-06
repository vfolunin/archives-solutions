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

    int l = 0, r = s.size() - 1;
    while (l < r && s[l] != s[r]) {
        l++;
        r--;
    }

    cout << r - l + 1;
}