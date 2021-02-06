#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second || a.second == b.second && a.first > b.first;
}

bool solve(int test) {
    string line;
    if (!getline(cin, line))
        return 0;

    map<int, int> countMap;
    for (char c : line)
        countMap[c]++;

    vector<pair<int, int>> countVector(countMap.begin(), countMap.end());
    sort(countVector.begin(), countVector.end(), compare);

    if (test)
        cout << "\n";
    for (auto &[code, count] : countVector)
        cout << code << " " << count << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}