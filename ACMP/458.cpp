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

    int rowCount;
    cin >> rowCount;

    vector<int> rowOrder(rowCount);
    for (int &rowIndex : rowOrder) {
        cin >> rowIndex;
        rowIndex--;
    }

    string s;
    cin >> s;

    vector<int> rowLen(rowCount, s.size() / rowCount);
    for (int i = 0; i < s.size() % rowCount; i++)
        rowLen[i]++;

    vector<string> rows(rowCount);
    int from = 0;
    for (int rowIndex : rowOrder) {
        rows[rowIndex] = s.substr(from, rowLen[rowIndex]);
        from += rowLen[rowIndex];
    }

    for (int x = 0; x < rows[0].size(); x++)
        for (int y = 0; y < rows.size(); y++)
            if (x < rows[y].size())
                cout << rows[y][x];
}