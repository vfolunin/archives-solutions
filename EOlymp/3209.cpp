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

    string left;
    for (int i = 0; i < count.size(); i++)
        left += string(count[i] / 2, 'a' + i);

    string right = left;
    reverse(right.begin(), right.end());

    for (int i = 0; i < count.size(); i++) {
        if (count[i] % 2) {
            left += 'a' + i;
            break;
        }
    }

    cout << left << right;
}