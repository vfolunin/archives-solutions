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

    vector<int> last(26, -1e9);
    int res = 1e9;

    for (int i = 0; i < s.size(); i++) {
        res = min(res, i - last[s[i] - 'a']);
        last[s[i] - 'a'] = i;
    }

    cout << (res < 1e9 ? res : 0);
}