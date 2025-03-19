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

    vector<int> a(h * w);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y * w + x] << " ";
        cout << "\n";
    }
}