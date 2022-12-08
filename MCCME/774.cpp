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

    for (int l = 0, r = s.size() / 2; l < s.size() / 2; l++, r++)
        cout << s[r] << s[l];

    if (s.size() % 2)
        cout << s.back();
}