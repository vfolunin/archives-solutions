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

    int h, w, cellCount;
    cin >> h >> w >> cellCount;

    vector<string> a(h, string(w, '.'));
    for (int i = 0; i < cellCount; i++) {
        int y, x;
        cin >> y >> x;

        a[y - 1][x - 1] = '*';
    }

    for (string &s : a)
        cout << s << "\n";
}