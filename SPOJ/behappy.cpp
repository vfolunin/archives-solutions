#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int targetSize, targetCount;
    cin >> targetSize >> targetCount;

    if (!targetSize && !targetCount)
        return 0;

    vector<vector<long long>> ways(targetSize + 1, vector<long long>(targetCount + 1));
    ways[0][0] = 1;

    for (int i = 1; i <= targetSize; i++) {
        int l, r;
        cin >> l >> r;

        for (int count = 0; count <= targetCount; count++)
            for (int take = l; take <= r; take++)
                if (count >= take)
                    ways[i][count] += ways[i - 1][count - take];
    }

    cout << ways[targetSize][targetCount] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}