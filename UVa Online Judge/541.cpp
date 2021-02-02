#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<vector<int>> a(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> a[i][j];

    set<int> oddRow;
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++)
            sum += a[i][j];
        if (sum % 2)
            oddRow.insert(i);
    }

    set<int> oddCol;
    for (int j = 0; j < size; j++) {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += a[i][j];
        if (sum % 2)
            oddCol.insert(j);
    }

    if (oddRow.empty() && oddCol.empty())
        cout << "OK\n";
    else if (oddRow.size() == 1 && oddCol.size() == 1)
        cout << "Change bit (" << *oddRow.begin() + 1 << "," << *oddCol.begin() + 1 << ")\n";
    else
        cout << "Corrupt\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}