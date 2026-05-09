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

    vector<int> row(size), col(size);
    for (int i = 1; i <= size * size; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        if (!row[y] && !col[x]) {
            row[y] = col[x] = 1;

            cout << i << " ";
        }
    }
}