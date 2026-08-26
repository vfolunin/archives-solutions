#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, double> read() {
    int h, m, s;
    double v = -1;
    char c;
    if (scanf("%d:%d:%d%c", &h, &m, &s, &c) == EOF)
        return { -1, v };
    if (c == ' ')
        scanf("%lf", &v);
    return { h * 3600 + m * 60 + s, v * 1000 / 3600 };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double speed = 0, lastTime = 0, distance = 0;

    while (1) {
        auto [curTime, curSpeed] = read();
        if (curTime == -1)
            break;

        distance += (curTime - lastTime) * speed;
        lastTime = curTime;

        if (curSpeed >= 0)
            speed = curSpeed;
        else
            printf("%02d:%02d:%02d %.2lf km\n", curTime / 3600, curTime % 3600 / 60, curTime % 60, distance / 1000);
    }
}