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

    int lightCount, colorCount;
    cin >> lightCount >> colorCount;

    vector<int> colorOccurenceCount(colorCount);
    for (int i = 0; i < lightCount; i++) {
        int color;
        cin >> color;
        colorOccurenceCount[color - 1]++;
    }

    int minOccurenceCount = *min_element(colorOccurenceCount.begin(), colorOccurenceCount.end());

    vector<int> res;
    for (int color = 0; color < colorCount; color++)
        if (colorOccurenceCount[color] == minOccurenceCount)
            res.push_back(color);

    cout << res.size() << "\n";
    for (int color : res)
        cout << color + 1 << " ";
}