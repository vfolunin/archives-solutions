#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readImage() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    return a;
}

bool contains(vector<string> &image, int fromY, int fromX, vector<string> &pattern) {
    for (int y = 0; y < pattern.size(); y++)
        for (int x = 0; x < pattern[0].size(); x++)
            if (pattern[y][x] == '#' && image[fromY + y][fromX + x] != '#')
                return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> pattern = readImage();
    vector<string> image = readImage();

    int res = 0;
    for (int fromY = 0; fromY + pattern.size() <= image.size(); fromY++)
        for (int fromX = 0; fromX + pattern[0].size() <= image[0].size(); fromX++)
            res += contains(image, fromY, fromX, pattern);

    cout << res;
}