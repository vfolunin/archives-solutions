#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_map<char, int> count;
    for (char c : s)
        count[c]++;

    vector<int> counts;
    for (auto &[c, count] : count)
        counts.push_back(count);

    sort(counts.begin(), counts.end());

    cout << (counts == vector<int>{ 1, 1, 2 });
}