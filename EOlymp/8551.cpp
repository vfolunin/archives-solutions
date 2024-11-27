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

    int targetSize, maxValue, maxRepeat;
    cin >> targetSize >> maxValue >> maxRepeat;

    vector ways(targetSize + 1, vector<long long>(maxValue + 1));
    ways[0][0] = 1;

    for (int size = 1; size <= targetSize; size++)
        for (int last = 1; last <= maxValue; last++)
            for (int prevSize = max(0, size - maxRepeat); prevSize < size; prevSize++)
                for (int prev = 0; prev < last; prev++)
                    ways[size][last] += ways[prevSize][prev];

    long long res = 0;
    for (int last = 1; last <= maxValue; last++)
        res += ways[targetSize][last];

    cout << res;
}