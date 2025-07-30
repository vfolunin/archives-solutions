#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

pair<int, int> rec(vector<int> &a, int i) {
    if (i == a.size()) {
        if (unordered_set<int>(a.begin(), a.end()).size() == a.size())
            return { 1, 0 };
        return { 0, 1 };
    }

    int winWays = 0, loseWays = 0;
    for (a[i] = 1; a[i] <= 6; a[i]++) {
        auto [nextWinWays, nextLoseWays] = rec(a, i + 1);
        winWays += nextWinWays;
        loseWays += nextLoseWays;
    }
    return { winWays, loseWays };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(4);
    for (int i = 0; i < size; i++)
        cin >> a[i];

    auto [winWays, loseWays] = rec(a, size);

    cout << winWays << " " << loseWays;
}