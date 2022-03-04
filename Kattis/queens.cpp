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

    vector<int> row(size), col(size), d1(size * 2), d2(size * 2);

    for (int i = 0; i < size; i++) {
        int y, x;
        cin >> y >> x;

        if (row[y] || col[x] || d1[y + x] || d2[y - x + size]) {
            cout << "INCORRECT";
            return 0;
        }

        row[y] = col[x] = d1[y + x] = d2[y - x + size] = 1;
    }

    cout << "CORRECT";
}