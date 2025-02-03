#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<vector<int>> &p, int y1, int x1, int y2, int x2) {
    int res = p[y2][x2];
    if (y1)
        res -= p[y1 - 1][x2];
    if (x1)
        res -= p[y2][x1 - 1];
    if (y1 && x1)
        res += p[y1 - 1][x1 - 1];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, side;
    cin >> h >> w >> side;

    vector<vector<int>> p(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            p[y][x] = c == '*';
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    int maxSum = 0, maxY1 = 0, maxX1 = 0, maxY2 = side - 1, maxX2 = side - 1;
    for (int y = 0; y + side <= h; y++) {
        for (int x = 0; x + side <= w; x++) {
            int sum = getSum(p, y + 1, x + 1, y + side - 2, x + side - 2);
            if (maxSum < sum) {
                maxSum = sum;
                maxY1 = y;
                maxX1 = x;
                maxY2 = y + side - 1;
                maxX2 = x + side - 1;
            }
        }
    }

    cout << maxSum << "\n";
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((maxY1 == y || y == maxY2) && (maxX1 == x || x == maxX2))
                cout << "+";
            else if (maxY1 < y && y < maxY2 && (maxX1 == x || x == maxX2))
                cout << "|";
            else if ((maxY1 == y || y == maxY2) && maxX1 < x && x < maxX2)
                cout << "-";
            else if (getSum(p, y, x, y, x))
                cout << "*";
            else
                cout << ".";
        }
        cout << "\n";
    }
}