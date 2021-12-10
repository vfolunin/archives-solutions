#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    int postCount;
    cin >> postCount;

    if (!postCount)
        return 0;

    vector<int> posts(postCount);
    for (int &p : posts)
        cin >> p;

    int onePos = find(posts.begin(), posts.end(), 1) - posts.begin();
    if (onePos == postCount) {
        cout << (postCount + 1) / 2 << "\n";
        return 1;
    }
    rotate(posts.begin(), posts.begin() + onePos, posts.end());

    int postRow = 0, res = 0;
    for (int p : posts) {
        if (p) {
            res += postRow / 2;
            postRow = 0;
        } else {
            postRow++;
        }   
    }
    res += postRow / 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}