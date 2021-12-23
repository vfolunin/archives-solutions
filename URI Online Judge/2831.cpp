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
    
    int boxCount;
    cin >> boxCount;

    vector<int> boxes(boxCount);
    for (int &box : boxes)
        cin >> box;

    boxes.push_back(0);
    sort(boxes.begin(), boxes.end());

    for (int i = 0; i + 1 < boxes.size(); i++) {
        if (boxes[i] + 8 < boxes[i + 1]) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
}