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

    s.insert(s.begin(), 'a');

    int res = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        int diff = abs(s[i] - s[i + 1]);
        res += min(diff, 26 - diff);
    }

    cout << res;
}