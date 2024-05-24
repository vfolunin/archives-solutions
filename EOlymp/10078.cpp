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
        count[tolower(c) - 'a']++;

    int res = -1;
    for (int i = 1; i < count.size(); i++)
        if (count[i] && (res == -1 || count[res] >= count[i]))
            res = i;

    cout << (char)(res + 'A');
}