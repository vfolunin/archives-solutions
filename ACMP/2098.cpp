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

    map<int, vector<int>> a;
    for (int i = 0; i < size; i++) {
        int y, x;
        cin >> y >> x;

        a[y].push_back(x);
    }

    int resY, resRow = 0;

    for (auto &[y, xs] : a) {
        sort(xs.begin(), xs.end());

        int row = 1, maxRow = 1;
        for (int i = 1; i < xs.size(); i++) {
            if (xs[i - 1] + 1 == xs[i])
                row++;
            else
                row = 1;

            maxRow = max(maxRow, row);
        }

        if (resRow <= maxRow) {
            resY = y;
            resRow = maxRow;
        }
    }

    cout << resY << " " << resRow;
}