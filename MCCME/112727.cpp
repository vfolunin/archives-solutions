#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size, h, w;
    cin >> size >> h >> w;

    vector<vector<string>> a(h, vector<string>(w));
    for (int i = 0; i < size; i++) {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                char c;
                cin >> c;
                a[y][x] += c;
            }
        }
    }

    unordered_set<string> values;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            values.insert(a[y][x]);

    cout << values.size();
}