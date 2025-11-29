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

    vector<int> dists(9);
    for (int y = 0; y < h; y++) {
        string s;
        cin >> s;

        for (int x = 0; x < w; x++)
            if (isdigit(s[x]))
                dists[s[x] - '1'] = w - x;
    }

    vector<int> sortedDists = dists;
    sort(sortedDists.begin(), sortedDists.end());
    sortedDists.erase(unique(sortedDists.begin(), sortedDists.end()), sortedDists.end());

    for (int dist : dists)
        cout << find(sortedDists.begin(), sortedDists.end(), dist) - sortedDists.begin() + 1 << "\n";
}