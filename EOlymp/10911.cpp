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

    int size;
    cin >> size;

    vector<pair<int, int>> pairs;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (pairs.empty() || value != pairs.back().first)
            pairs.push_back({ value, 1 });
        else
            pairs.back().second++;
    }

    int res = 0;
    for (int i = 1; i < pairs.size(); i++)
        res = max(res, min(pairs[i - 1].second, pairs[i].second) * 2);

    cout << res;
}