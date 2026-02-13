#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isHashtag(string &s) {
    if (s.size() < 2 || s[0] != '#')
        return 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == '#')
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> count;
    for (string s; cin >> s; )
        if (isHashtag(s))
            count[s]++;

    cout << count.size() << "\n";
    for (auto &[s, count] : count)
        cout << s << " " << count << "\n";
}