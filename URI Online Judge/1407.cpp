#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w, maxValue;
    cin >> h >> w >> maxValue;

    if (!h && !w)
        return 0;

    vector<int> count(maxValue);
    for (int i = 0; i < h * w; i++) {
        int value;
        cin >> value;
        count[value - 1]++;
    }

    int minCount = *min_element(count.begin(), count.end());

    vector<int> res;
    for (int value = 0; value < maxValue; value++)
        if (count[value] == minCount)
            res.push_back(value);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] + 1 << (i + 1 < res.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}