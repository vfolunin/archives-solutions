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

    vector<string> a(size);
    int cCount = 0;
    for (string &row : a) {
        cin >> row;
        cCount += count(row.begin(), row.end(), 'C');
    }
    cCount /= 2;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cout << (cCount > 0 ? 1 : 2);
            cCount -= a[y][x] == 'C';
        }
        cout << "\n";
    }
}