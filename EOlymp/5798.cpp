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

    string mask = string(s.size() / 2, '0') + string(s.size() / 2, '1');
    int res = 1e5;

    do {
        int cur = 0;
        for (int i = 0; i < s.size(); i++)
            if (mask[i] == '1')
                cur = cur * 10 + s[i] - '0';
        res = min(res, cur);
    } while (next_permutation(mask.begin(), mask.end()));

    cout << res;
}