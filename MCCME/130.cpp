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

    int p = s.size() - 1;
    while (p >= 0 && s[p] == '9')
        p--;

    if (p >= 0) {
        s[p]++;
        fill(s.begin() + p + 1, s.end(), '0');
    } else {
        s = "1" + string(s.size(), '0');
    }

    cout << s;
}