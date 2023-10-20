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

    vector<string> partition(s.size() + 1);
    vector<int> cost(s.size() + 1, -1e9);
    cost[0] = 0;

    vector<pair<string, int>> patterns = {
        { "ab", 0 }, { "aa", 2 }, { "abc", 0 }, { "aba", 2 }, { "aab", 2 }, { "abb", 2 },
        { "aaa", 3 }, { "abcd", 0 }, { "abac", 2 }, { "baca", 2 }, { "abab", 3 }, { "aabb", 3 },
        { "abba", 4 }, { "baaa", 3 }, { "abaa", 3 }, { "aaba", 3 }, { "aaab", 3 }, { "aaaa", 5 }
    };

    for (int len = 1; len <= s.size(); len++) {
        for (auto &[pattern, bonus] : patterns) {
            bool ok = len >= pattern.size();

            for (int i = 0; ok && i < pattern.size(); i++)
                for (int j = i + 1; ok && j < pattern.size(); j++)
                    ok &= pattern[i] != pattern[j] || s[len - pattern.size() + i] == s[len - pattern.size() + j];

            if (ok && cost[len - pattern.size()] != -1e9 && cost[len] < cost[len - pattern.size()] + bonus) {
                cost[len] = cost[len - pattern.size()] + bonus;
                if (len == pattern.size())
                    partition[len] = s.substr(0, pattern.size());
                else
                    partition[len] = partition[len - pattern.size()] + "-" + s.substr(len - pattern.size(), pattern.size());
            }
        }
    }

    cout << partition[s.size()] << "\n" << cost[s.size()];
}