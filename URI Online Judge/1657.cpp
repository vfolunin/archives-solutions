#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void check(unordered_map<string, int> &dict, const string &s, int &index) {
    auto it = dict.find(s);
    if (it != dict.end() && index > it->second)
        index = it->second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dictCount;
    cin >> dictCount;

    vector<string> dictWords(dictCount);
    unordered_map<string, int> dict;
    for (int i = 0; i < dictCount; i++) {
        cin >> dictWords[i];
        dict[dictWords[i]] = i;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string s;
        cin >> s;

        if (dict.count(s)) {
            cout << s << " is correct\n";
            continue;
        }

        int index = dict.size();

        for (int i = 0; i < s.size(); i++) {
            check(dict, s.substr(0, i) + s.substr(i + 1), index);
            for (char c = 'a'; c <= 'z'; c++) {
                check(dict, s.substr(0, i) + c + s.substr(i), index);
                check(dict, s.substr(0, i) + c + s.substr(i + 1), index);
            }
        }
        for (char c = 'a'; c <= 'z'; c++)
            check(dict, s + c, index);
        for (int i = 1; i < s.size(); i++) {
            swap(s[i - 1], s[i]);
            check(dict, s, index);
            swap(s[i - 1], s[i]);
        }

        if (index < dict.size())
            cout << s << " is a misspelling of " << dictWords[index] << "\n";
        else
            cout << s << " is unknown\n";
    }
}