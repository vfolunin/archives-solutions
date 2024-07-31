#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    vector<int> aCount(26);
    for (char c : a)
        aCount[c - 'a']++;

    vector<int> bCount(26);
    for (char c : b)
        bCount[c - 'a']++;

    int res = a.size() + b.size();
    for (int i = 0; i < aCount.size(); i++)
        res -= 2 * min(aCount[i], bCount[i]);

    cout << "Case #" << test << ":  " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;
    cin.ignore();

    for (int test = 1; test <= testCount; test++)
        solve(test);
}