#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string countAndSay(string &s) {
    vector<pair<char, int>> groups;
    for (char c : s) {
        if (groups.empty() || groups.back().first != c)
            groups.push_back({ c, 1 });
        else
            groups.back().second++;
    }

    stringstream ss;
    for (auto &[c, count] : groups)
        ss << count << c;
    return ss.str();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    n--;

    string s = "1";
    for (int i = 0; i < n; i++)
        s = countAndSay(s);

    cout << s;
}