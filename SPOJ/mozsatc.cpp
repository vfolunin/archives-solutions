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
    int limit;
    cin >> s >> limit;

    int count = 0, res = 0;
    for (int l = 0, r = 0; r < s.size(); r++) {
        count += s[r] == ',';
        while (count > limit)
            count -= s[l++] == ',';

        res = max(res, r - l + 1);
    }

    cout << res;
}