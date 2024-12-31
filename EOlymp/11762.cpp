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

    string res = s;
    for (int i = 0; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        res = max(res, s);
    }

    cout << res;
}