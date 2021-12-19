#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(int p[][500], int y, int x, int size) {
    int res = p[y + size - 1][x + size - 1];
    if (y)
        res -= p[y - 1][x + size - 1];
    if (x)
        res -= p[y + size - 1][x - 1];
    if (y && x)
        res += p[y - 1][x - 1];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, moveCount;
    scanf("%d%d", &size, &moveCount);

    static int p[2][500][500];
    for (int i = 0; i < moveCount * 2; i++) {
        int y, x;
        scanf("%d%d", &y, &x);
        p[i >= moveCount][y - 1][x - 1] = 1;
    }

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (y)
                    p[i][y][x] += p[i][y - 1][x];
                if (x)
                    p[i][y][x] += p[i][y][x - 1];
                if (y && x)
                    p[i][y][x] -= p[i][y - 1][x - 1];
            }
        }
    }

    vector<int> areaCount(2);
    for (int s = 1; s <= size; s++) {
        for (int y = 0; y + s <= size; y++) {
            for (int x = 0; x + s <= size; x++) {
                areaCount[0] += sum(p[0], y, x, s) && !sum(p[1], y, x, s);
                areaCount[1] += !sum(p[0], y, x, s) && sum(p[1], y, x, s);
            }
        }
    }

    printf("%d %d\n", areaCount[0], areaCount[1]);
}