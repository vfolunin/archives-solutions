#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    if (!(cin >> s))
        return 0;

    string to(26, ' ');
    for (char &c : to)
        cin >> c;

    int ruleCount;
    cin >> ruleCount;
    
    vector<pair<int, pair<char, char>>> rules(ruleCount);
    for (auto &[from, c] : rules)
        cin >> from >> c.first >> c.second;

    for (int i = 0, ri = 0; i < s.size(); i++) {
        while (ri < ruleCount && i == rules[ri].first) {
            to[rules[ri].second.first - 'a'] = rules[ri].second.second;
            ri++;
        }
        s[i] = to[s[i] - 'a'];
    }

    cout << "Case #" << test << ": The encoding string is " << s << ".\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}