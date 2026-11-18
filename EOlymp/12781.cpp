#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    string s;
    cin >> s >> count >> s;

    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'G')
            pos.push_back(i);

    int res = 1e9;
    for (int l = 0, r = count - 1; r < pos.size(); l++, r++)
        res = min(res, pos[r] - pos[l] + 1);

    cout << res;
}