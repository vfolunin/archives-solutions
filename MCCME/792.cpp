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

    string res;

    if (s.size() % 3 == 1)
        res += s[0];
    else if (s.size() % 3 == 2)
        res += s.substr(0, 2);

    for (int i = s.size() % 3; i < s.size(); i += 3) {
        if (i)
            res += ",";
        res += s.substr(i, 3);
    }

    cout << res;
}