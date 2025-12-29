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

    vector<int> col;
    for (int y = 0; y < size; y++) {
        vector<int> row(size);
        for (int &value : row)
            cin >> value;

        nth_element(row.begin(), row.begin() + row.size() / 2, row.end());
        col.push_back(row[row.size() / 2]);
    }

    nth_element(col.begin(), col.begin() + col.size() / 2, col.end());
    
    cout << col[col.size() / 2] << "\n";
}