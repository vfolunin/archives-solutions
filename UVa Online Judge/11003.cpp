#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int boxCount;
    cin >> boxCount;

    if (!boxCount)
        return 0;

    vector<int> maxLoad(boxCount + 1, -1);
    maxLoad[0] = 1e9;

    for (int i = 0; i < boxCount; i++) {
        int weight, load;
        cin >> weight >> load;

        for (int h = boxCount - 1; h >= 0; h--)
            if (maxLoad[h] >= weight)
                maxLoad[h + 1] = max(maxLoad[h + 1], min(maxLoad[h] - weight, load));
    }

    int res = boxCount;
    while (maxLoad[res] == -1)
        res--;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}