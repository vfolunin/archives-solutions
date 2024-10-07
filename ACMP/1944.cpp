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

    int h, w, rowCount, colCount;
    cin >> h >> w >> rowCount >> colCount;

    vector<int> rows(rowCount);
    for (int &row : rows)
        cin >> row;

    vector<int> cols(colCount);
    for (int &col : cols)
        cin >> col;

    int parkCells = 0;
    for (int ri = 0; ri + 1 < rows.size(); ri++)
        for (int ci = 0; ci + 1 < cols.size(); ci++)
            parkCells += max(rows[ri + 1] - rows[ri] - 3, 0) * max(cols[ci + 1] - cols[ci] - 3, 0);

    int streetCells = rowCount * w + colCount * (h - rowCount);

    cout << h * w - parkCells - streetCells << " " << parkCells << " " << streetCells;
    
}