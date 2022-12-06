#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getNext(string &s) {
    vector<pair<char, int>> parts;
    for (char c : s) {
        if (parts.empty() || parts.back().first != c)
            parts.push_back({ c, 1 });
        else
            parts.back().second++;
    }

    string res;
    for (auto &[c, count] : parts)
        res += to_string(count) + c;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int n;
    cin >> s >> n;

    for (int i = 0; i < n - 1; i++)
        s = getNext(s);

    cout << s;
}