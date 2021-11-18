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

    int n;
    cin >> n;

    vector<vector<int>> a(100, vector<int>(100));

    for (int i = 0; i < n; i++) {
        int y1, y2, x1, x2;
        cin >> y1 >> y2 >> x1 >> x2;
        for (int y = y1; y < y2; y++)
            for (int x = x1; x < x2; x++)
                a[y][x] = 1;
    }

    int res = 0;
    for (vector<int> &row : a)
        for (int elem : row)
            res += elem;
    
    cout << res << "\n";
}