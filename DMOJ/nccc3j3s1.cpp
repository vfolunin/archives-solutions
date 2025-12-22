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

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    sort(count.rbegin(), count.rend());

    cout << s.size() - count[0] - count[1] << "\n";
}