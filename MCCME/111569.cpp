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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<int> last(26, -1);
    int curLen = 0, resLen = 0, resFrom = -1;

    for (int i = 0; 1; i++) {
        char c;
        if (!(cin >> c))
            break;
        s += c;

        curLen = min(curLen + 1, i - last[c - 'a']);
        if (resLen < curLen) {
            resLen = curLen;
            resFrom = i - resLen + 1;
        }
        last[c - 'a'] = i;
    }

    cout << s.substr(resFrom, resLen);
}