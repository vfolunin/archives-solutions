#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> encode(string &s) {
    map<char, int> pos;
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
        if (!pos.count(s[i]))
            pos[s[i]] = i;
        res.push_back(pos[s[i]]);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    map<vector<int>, int> count;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        count[encode(s)]++;
    }

    int res = 0;
    for (auto &[_, count] : count)
        res += count * (count - 1) / 2;

    cout << res;
}