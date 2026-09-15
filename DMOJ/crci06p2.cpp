#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> getPiece(int type) {
    static vector<string> pieces = {
        "x...........................",
        "x...........................",
        "x...xx...xx.xx...x....x.x...",
        "x...xx..xx...xx.xxx.xxx.xxx."
    };

    vector<string> piece(4);
    for (int i = 0; i < 4; i++)
        piece[i] = pieces[i].substr(type * 4, 4);
    return piece;
}

void rotate(vector<string> &piece) {
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            swap(piece[y][x], piece[x][3 - y]);
            swap(piece[x][3 - y], piece[3 - y][3 - x]);
            swap(piece[3 - y][3 - x], piece[3 - x][y]);
        }
    }
}

vector<int> getHeights(vector<string> &piece) {
    vector<int> maxY(4, -1);
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if (piece[y][x] == 'x')
                maxY[x] = y;

    maxY.erase(remove(maxY.begin(), maxY.end(), -1), maxY.end());

    int base = *max_element(maxY.begin(), maxY.end());
    for (int &y : maxY)
        y = base - y;

    return maxY;
}

bool can(vector<int> &heights, vector<int> &baseHeights, int from) {
    int base = baseHeights[from] - heights[0];
    for (int i = 1; i < heights.size(); i++)
        if (base != baseHeights[from + i] - heights[i])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, type;
    cin >> size >> type;

    vector<int> baseHeights(size);
    for (int &height : baseHeights)
        cin >> height;

    vector<string> piece = getPiece(type - 1);
    int wayCount = 0;

    for (int i = 0; i < 4; i++) {
        vector<int> heights = getHeights(piece);
        for (int from = 0; from + heights.size() <= baseHeights.size(); from++)
            wayCount += can(heights, baseHeights, from);
        rotate(piece);
    }

    if (type == 2)
        wayCount /= 4;
    else if (type == 1 || type == 3 || type == 4)
        wayCount /= 2;

    cout << wayCount;
}