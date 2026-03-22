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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    map<int, vector<int>> rectangles;
    for (int i = 0; i < size; i++) {
        int h, w;
        cin >> h >> w;

        if (h > w)
            swap(h, w);

        rectangles[h].push_back(w);
    }

    int res = 0, maxW = -1;
    for (auto it = rectangles.rbegin(); it != rectangles.rend(); it++) {
        for (int w : it->second)
            res += w >= maxW;
        maxW = max(maxW, *max_element(it->second.begin(), it->second.end()));
    }

    cout << res;
}