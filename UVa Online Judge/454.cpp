#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<char, int> getCount(string &s) {
    map<char, int> count;
    for (char c : s)
        if (c != ' ')
            count[c]++;
    return count;
}

void solve(int test) {
    map<map<char, int>, vector<string>> groups;

    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;
        groups[getCount(line)].push_back(line);
    }

    vector<pair<string, string>> res;
    for (auto &[_, group] : groups) {
        sort(group.begin(), group.end());
        for (int i = 0; i < group.size(); i++)
            for (int j = i + 1; j < group.size(); j++)
                res.push_back({ group[i], group[j] });
    }

    sort(res.begin(), res.end());

    if (test)
        cout << "\n";
    for (auto &[a, b] : res)
        cout << a << " = " << b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}