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

    int row = 1, maxRow = 1;
    for (int i = 1; i < a.size(); i++) {
        if (abs(a[i] - a[i - 1]) <= 2)
            row++;
        else
            row = 1;
        maxRow = max(maxRow, row);
    }

    cout << maxRow;
}