#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int partCount;
    cin >> partCount;

    if (partCount == -1)
        return 0;

    vector<pair<int, int>> parts(partCount);
    for (auto &[speed, time] : parts)
        cin >> speed >> time;

    int distance = 0;
    for (int i = 0; i < partCount; i++)
        distance += parts[i].first * (parts[i].second - (i ? parts[i - 1].second : 0));

    cout << distance << " miles\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}