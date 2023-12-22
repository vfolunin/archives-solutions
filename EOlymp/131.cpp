#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> readCount() {
    string s;
    getline(cin, s);

    unordered_map<char, int> count;
    for (char c : s)
        count[c]++;
    return count;
}

bool canMake(const unordered_map<char, int> &aCount, const unordered_map<char, int> &bCount) {
    for (auto &[c, _] : bCount)
        if (!aCount.count(c) || aCount.at(c) < bCount.at(c))
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<char, int> count = readCount();

    int queryCount;
    cin >> queryCount;
    cin.ignore();

    int res = 0;
    for (int i = 0; i < queryCount; i++)
        res += canMake(count, readCount());

    cout << res;
}