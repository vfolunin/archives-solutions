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

    char c = 'a';
    while (s.find(c) != -1)
        c++;

    vector<int> count(26);
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        if (i >= 2 && s[i - 2] == s[i] && s[i - 1] == s[i]) {
            count[s[i] - 'a']--;
            s[i] = c;
            count[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (count[s[i] - 'a'] * 2 > s.size()) {
            count[s[i] - 'a']--;
            s[i] = min_element(count.begin(), count.end()) - count.begin() + 'a';
            count[s[i] - 'a']++;
        }
    }

    cout << s;
}