#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if (!h && !m)
        return 0;

    int t = h * 60 + m;
    t %= 12 * 60;

    double hAngle = t / (12.0 * 60.0) * 360;
    double mAngle = (t % 60) / 60.0 * 360;

    double diff = abs(hAngle - mAngle);
    diff = min(diff, 360 - diff);
    printf("%.3lf\n", diff);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}