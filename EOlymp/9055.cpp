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

    long long res = 0;
    for (char c : s)
        if (count[c - 'a'] > 1)
            res = 1;
    for (char a : s)
        for (char b = a + 1; b <= 'z'; b++)
            res += count[b - 'a'];

    cout << res;
}