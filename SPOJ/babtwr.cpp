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

    vector<vector<int>> boxes;
    for (int i = 0; i < boxCount; i++) {
        vector<int> box(3);
        for (int &size : box)
            cin >> size;

        sort(box.begin(), box.end());
        do {
            boxes.push_back(box);
        } while (next_permutation(box.begin(), box.end()));
    }

    sort(boxes.begin(), boxes.end(), [](auto &l, auto &r) {
        return l[0] * l[1] > r[0] * r[1];
    });

    vector<int> height(boxes.size());
    for (int i = 0; i < height.size(); i++) {
        height[i] = boxes[i][2];
        for (int j = 0; j < i; j++)
            if (boxes[j][0] > boxes[i][0] && boxes[j][1] > boxes[i][1])
                height[i] = max(height[i], height[j] + boxes[i][2]);
    }

    cout << *max_element(height.begin(), height.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}