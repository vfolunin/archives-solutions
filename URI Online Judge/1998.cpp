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

    if (boxCount == -1)
        return 0;

    vector<int> boxes(boxCount);
    for (int &box : boxes)
        cin >> box;

    while (1) {
        int i = 0;
        while (i < boxCount && boxes[i] != i + 1)
            i++;

        if (i == boxCount)
            break;

        for (int j = 0; j < i; j++)
            boxes[j]++;
        boxes[i] = 0;
    }
    
    cout << (count(boxes.begin(), boxes.end(), 0) == boxCount ? "S\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}