#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const pair<char, int> &a, const pair<char, int> &b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first > b.first;
}

bool solve(int test) {
    string s;
    if (!getline(cin, s))
        return 0;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    vector<pair<char, int>> freqs(count.begin(), count.end());
    sort(freqs.begin(), freqs.end(), compare);

    if (test)
        cout << "\n";
    for (auto &[c, k] : freqs)
        cout << (int)c << " " << k << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}