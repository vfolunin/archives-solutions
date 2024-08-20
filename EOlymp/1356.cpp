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

    int size, voteCount;
    cin >> size >> voteCount;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++)
        count[i];

    for (int i = 0; i < voteCount; i++) {
        int vote;
        cin >> vote;
        count[vote - 1]++;
    }

    vector<pair<int, int>> pairs(count.begin(), count.end());
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < 3; i++)
        cout << pairs[i].first + 1 << " ";
}