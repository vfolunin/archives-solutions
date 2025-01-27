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

    int cur = 0, res = 0;
    for (char c : s) {
        if (c == 'Y')
            cur++;
        else
            cur = 0;
        res = max(res, cur);
    }

    cout << res;
}