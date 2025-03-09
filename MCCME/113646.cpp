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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<vector<int>> can(size + 1, vector<int>(2));
    can[0][0] = 1;

    for (int i = 1; i <= size; i++) {
        if (a[i - 1] == 0) {
            can[i][0] = can[i - 1][0];
            can[i][1] = 0;
        } else if (a[i - 1] % 2) {
            can[i][0] = can[i - 1][1];
            can[i][1] = can[i - 1][0];
        } else {
            can[i][0] = can[i - 1][0];
            can[i][1] = can[i - 1][1];
        }
    }

    cout << (can[size][0] ? "YES" : "NO");
}