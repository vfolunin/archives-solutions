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

    string need, have;
    cin >> need >> have;

    vector<int> count(26);
    for (char c : need)
        count[c - 'A']++;
    for (char c : have)
        count[c - 'A']--;

    int res = 0;
    for (int count : count)
        res += max(count, 0);

    cout << res << "\n";
}