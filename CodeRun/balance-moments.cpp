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
    cin >> s;

    unordered_map<char, vector<int>> pos;
    for (int i = 0; i < s.size(); i++)
        pos[s[i]].push_back(i);

    char c;
    cin >> c;
    vector<int> &p = pos[c];

    if (p.size() % 2)
        cout << p[p.size() / 2] << " " << p[p.size() / 2];
    else if (p.empty())
        cout << "0 " << s.size() - 1;
    else if (p[p.size() / 2 - 1] + 1 <= p[p.size() / 2] - 1)
        cout << p[p.size() / 2 - 1] + 1 << " " << p[p.size() / 2] - 1;
}