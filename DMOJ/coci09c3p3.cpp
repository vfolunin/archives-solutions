#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, typeCount;
    cin >> size >> typeCount;

    vector<int> a(size);
    map<int, int> occurenceCount, firstOccurence;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        occurenceCount[a[i]]++;
        if (occurenceCount[a[i]] == 1)
            firstOccurence[a[i]] = i;
    }

    vector<pair<int, int>> pairs;
    for (auto &[value, count] : occurenceCount)
        pairs.push_back({ count, firstOccurence[value] });

    sort(pairs.begin(), pairs.end(), compare);

    for (auto &[occurenceCount, firstOccurence] : pairs)
        for (int i = 0; i < occurenceCount; i++)
            cout << a[firstOccurence] << " ";
}