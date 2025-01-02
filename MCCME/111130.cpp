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
 
    int polygonCount;
    cin >> polygonCount;

    vector<pair<int, int>> pairs;
    for (int i = 0; i < polygonCount; i++) {
        int pointCount;
        cin >> pointCount;

        int minX = 2.1e9;
        for (int i = 0; i < pointCount; i++) {
            int x, y;
            cin >> x >> y;

            minX = min(minX, x);
        }
        
        pairs.push_back({ minX, i });
    }

    sort(pairs.begin(), pairs.end());
    for (int i = 0; i < pairs.size(); i++)
        pairs[i].first = i;
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    for (auto &[count, _] : pairs)
        cout << count << " ";
}