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

    map<char, long long> count;
    for (int i = 0; i < s.size(); i++)
        count[s[i]] += (i + 1LL) * (s.size() - i);

    for (auto &[c, count] : count)
        cout << c << ": " << count << "\n";
}