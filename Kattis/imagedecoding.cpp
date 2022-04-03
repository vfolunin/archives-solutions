#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int rowCount;
    cin >> rowCount;

    if (!rowCount)
        return 0;

    if (test)
        cout << "\n";

    set<int> colCounts;
    for (int i = 0; i < rowCount; i++) {
        char c;
        cin >> c;

        int colCount = 0;
        while (cin.peek() != '\n') {
            int width;
            cin >> width;

            cout << string(width, c);
            c = '.' + '#' - c;
            colCount += width;
        }

        cout << "\n";
        colCounts.insert(colCount);
    }

    if (colCounts.size() > 1)
        cout << "Error decoding image\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}