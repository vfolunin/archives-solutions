#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    unordered_map<string, int> count;
    string res;

    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == ' ' || s[i + 1] == ' ')
            continue;

        string cur = s.substr(i, 2);
        count[cur]++;

        if (res == "" || count[res] < count[cur] || count[res] == count[cur] && res < cur)
            res = cur;
    }

    cout << res;
}