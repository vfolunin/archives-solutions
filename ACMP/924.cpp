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

    vector<string> a(4);
    for (string &row : a)
        cin >> row;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (a[y][x] == a[y + 1][x] && a[y][x] == a[y][x + 1] && a[y][x] == a[y + 1][x + 1]) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}