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

    int size, diffLimit;
    cin >> size >> diffLimit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int rowCount = 1, curRow = 1, maxRow = 1;
    for (int i = 1; i < a.size(); i++) {
        if (abs(a[i - 1] - a[i]) <= diffLimit) {
            curRow++;
            maxRow = max(maxRow, curRow);
        } else {
            curRow = 1;
            rowCount++;
        }
    }

    cout << rowCount << "\n" << maxRow;
}