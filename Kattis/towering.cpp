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

    vector<int> boxes(6);
    for (int &height : boxes)
        cin >> height;

    vector<int> towers(2);
    for (int &height : towers)
        cin >> height;

    sort(boxes.begin(), boxes.end());
    do {
        if (boxes[0] > boxes[1] && boxes[1] > boxes[2] && boxes[0] + boxes[1] + boxes[2] == towers[0] &&
            boxes[3] > boxes[4] && boxes[4] > boxes[5] && boxes[3] + boxes[4] + boxes[5] == towers[1])
            break;
    } while (next_permutation(boxes.begin(), boxes.end()));

    for (int height : boxes)
        cout << height << " ";
}