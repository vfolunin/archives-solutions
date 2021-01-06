#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Box {
    int index;
    vector<int> dimensions;
    double volume;

    bool operator < (const Box &that) const {
        return volume < that.volume;
    }

    bool fitsIn(const Box &that) const {
        for (int i = 0; i < dimensions.size(); i++)
            if (dimensions[i] >= that.dimensions[i])
                return 0;
        return 1;
    }
};

bool solve() {
    int boxCount, dimensionCount;
    if (!(cin >> boxCount >> dimensionCount))
        return 0;

    vector<Box> boxes(boxCount);
    for (int i = 0; i < boxCount; i++) {
        boxes[i].index = i + 1;
        boxes[i].dimensions.resize(dimensionCount);
        boxes[i].volume = 1;
        for (int j = 0; j < dimensionCount; j++) {
            cin >> boxes[i].dimensions[j];
            boxes[i].volume *= boxes[i].dimensions[j];
        }
        sort(boxes[i].dimensions.begin(), boxes[i].dimensions.end());
    }
    sort(boxes.begin(), boxes.end());

    vector<int> lisLength(boxCount, 1), prevBox(boxCount, -1);
    for (int i = 0; i < boxCount; i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[j].fitsIn(boxes[i]) && lisLength[j] + 1 > lisLength[i]) {
                lisLength[i] = lisLength[j] + 1;
                prevBox[i] = j;
            }
        }
    }

    int last = max_element(lisLength.begin(), lisLength.end()) - lisLength.begin();
    cout << lisLength[last] << "\n";

    vector<int> answer;
    for (; last != -1; last = prevBox[last])
        answer.push_back(boxes[last].index);
    reverse(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << (i + 1 < answer.size() ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}