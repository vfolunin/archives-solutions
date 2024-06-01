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

    int size, limit;
    cin >> size >> limit;

    string row;
    int rowSize = 0;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        if (rowSize + s.size() <= limit) {
            if (rowSize)
                row += " ";
            row += s;
            rowSize += s.size();
        } else {
            cout << row << "\n";
            row = s;
            rowSize = s.size();
        }
    }

    cout << row << "\n";
}