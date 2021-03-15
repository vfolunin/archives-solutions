#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    static vector<string> ds = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
    static double d = sqrt(2) / 2;
    static vector<double> dy = { 1, d, 0, -d, -1, -d, 0, d };
    static vector<double> dx = { 0, d, 1, d, 0, -d, -1, -d };

    double y = 0, x = 0;
    while (1) {
        int step;
        char direction[10] = {}, delimiter;
        if (scanf("%d%[^,.]%c", &step, &direction, &delimiter) != 3)
            return 0;

        int d = find(ds.begin(), ds.end(), direction) - ds.begin();
        y += step * dy[d];
        x += step * dx[d];

        if (delimiter == '.')
            break;
    }

    printf("Map #%d\n", test);
    printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
    printf("The distance to the treasure is %.3lf.\n\n", hypot(x, y));
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}