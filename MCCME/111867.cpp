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

    string s = string(9, 'R') + "D";
    for (int i = 0; i < 4; i++) {
        s += string(8, 'L') + "D";
        s += string(8, 'R') + "D";
    }
    s += string(9, 'L') + string(9, 'U');

    string res;
    for (int i = 0; i < 38; i++)
        res += s;
    res.erase(0, 2);

    cout << res.size() << "\n" << res;
}