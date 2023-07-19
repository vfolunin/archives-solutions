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

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    string colors = "BGR";

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int mask;
            cin >> mask;

            if (a[y][x] != '.' && !(mask & (1 << colors.find(a[y][x])))) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}