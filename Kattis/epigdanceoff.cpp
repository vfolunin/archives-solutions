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

    vector<int> marked(w);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;
            marked[x] |= c == '$';
        }
    }

    cout << count(marked.begin(), marked.end(), 0) + 1;
}