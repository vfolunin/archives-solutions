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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int curRow = 1, maxRow = 1;
    long long count = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] == a[i]) {
            curRow++;
        } else {
            count += curRow * (curRow + 1LL) / 2;
            curRow = 1;
        }
        maxRow = max(maxRow, curRow);
    }
    count += curRow * (curRow + 1LL) / 2;
    maxRow = max(maxRow, curRow);

    cout << count << " " << maxRow;
}