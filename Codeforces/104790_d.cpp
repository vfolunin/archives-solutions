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

    vector<vector<int>> count(w, vector<int>(26));
    for (int y = 0; y < h; y++) {
        string s;
        cin >> s;

        for (int x = 0; x < w; x++)
            count[x][s[x] - 'a']++;
    }

    for (vector<int> &count : count)
        cout << (char)(max_element(count.begin(), count.end()) - count.begin() + 'a');
}