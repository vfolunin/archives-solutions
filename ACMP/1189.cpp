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

    vector<vector<int>> a(3, vector<int>(3));
    int sum;
    cin >> a[0][0] >> a[0][1] >> a[2][1] >> a[2][2] >> sum;

    a[0][2] = sum - a[0][0] - a[0][1];
    a[2][0] = sum - a[2][1] - a[2][2];
    a[1][0] = sum - a[0][0] - a[2][0];
    a[1][1] = sum - a[0][1] - a[2][1];
    a[1][2] = sum - a[0][2] - a[2][2];

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            if (a[y][x] <= 0) {
                cout << "No";
                return 0;
            }
        }
    }

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}