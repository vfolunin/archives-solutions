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

    int boxCount, screwsPerTable, tableCount;
    cin >> boxCount >> screwsPerTable >> tableCount;

    vector<int> boxes(boxCount);
    for (int &box : boxes)
        cin >> box;
    sort(boxes.rbegin(), boxes.rend());

    int screwsCount = screwsPerTable * tableCount;
    int res = 0;
    while (screwsCount > 0)
        screwsCount -= boxes[res++];

    cout << res;
}