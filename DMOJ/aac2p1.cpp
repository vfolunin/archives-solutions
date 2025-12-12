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
    cin >> s >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    int res = 0;
    for (int count : count)
        res += count % 2;

    cout << max(res, 1);
}