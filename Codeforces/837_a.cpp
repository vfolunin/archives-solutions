#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int upperCount(string &s) {
    int res = 0;
    for (char c : s)
        res += (bool)isupper(c);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int res = 0;
    for (string s; cin >> s; )
        res = max(res, upperCount(s));

    cout << res;
}