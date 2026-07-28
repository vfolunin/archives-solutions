#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double dist, coord, speed, greenTime, redTime;
    cin >> dist >> coord >> speed >> greenTime >> redTime;

    double time = coord / speed;
    time -= floor(time / (greenTime + redTime)) * (greenTime + redTime);

    if (time < greenTime)
        cout << fixed << dist / speed;
    else
        cout << fixed << dist / speed + greenTime + redTime - time;
}