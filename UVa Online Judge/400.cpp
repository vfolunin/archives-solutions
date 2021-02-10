#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int nameCount;
    if (!(cin >> nameCount))
        return 0;

    vector<string> names(nameCount);
    int maxNameSize = 0;
    for (string &name : names) {
        cin >> name;
        maxNameSize = max<int>(maxNameSize, name.size());
    }

    int colCount = 62 / (maxNameSize + 2);
    int rowCount = (nameCount + colCount - 1) / colCount;

    sort(names.begin(), names.end());

    cout << string(60, '-') << "\n";
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            if (col * rowCount + row < nameCount)
                cout << setw(maxNameSize) << left << names[col * rowCount + row];
            if ((col + 1) * rowCount + row < nameCount)
                cout << "  ";
        }
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}