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

    int size;
    cin >> size;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    vector<int> counts;
    for (auto &[_, count] : count)
        counts.push_back(count);
    sort(counts.rbegin(), counts.rend());

    int res = 0;
    for (int i = 0; i < 2 && i < counts.size(); i++)
        res += counts[i];

    cout << res;
}