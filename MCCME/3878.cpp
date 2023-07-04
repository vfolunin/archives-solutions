#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Post {
    int index, coord;

    bool operator < (const Post &that) const {
        return coord < that.coord;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int postCount, width;
    cin >> postCount >> width;
    postCount += 2;

    vector<Post> posts(postCount);
    cin >> posts[0].coord >> posts[1].coord;
    for (int i = 2; i < postCount; i++) {
        posts[i].index = i - 2;
        cin >> posts[i].coord;
    }
    sort(posts.begin(), posts.end());

    if (posts[postCount - 1].coord - posts[0].coord < width) {
        cout << -1;
        return 0;
    }

    if (width == 0) {
        cout << 0;
        return 0;
    }

    int resCount = postCount - 2, resFrom = 1;
    for (int l = 0, r = 0; l < postCount; l++) {
        while (r < postCount && posts[r].coord - posts[l].coord < width)
            r++;

        if (r < postCount && r - l - 1 < resCount) {
            resCount = r - l - 1;
            resFrom = l + 1;
        }
    }

    cout << resCount << "\n";
    for (int i = 0; i < resCount; i++)
        cout << posts[resFrom + i].index + 1 << "\n";
}