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

    double dist, time, dist1, speed1, speed2;
    cin >> dist >> time >> dist1 >> speed1 >> speed2;

    time *= 60;
    double dist2 = dist - dist1;

    double needTime = dist1 / speed1 + dist2 / speed2;
    
    cout << max<int>(ceil((needTime - time) / 60), 0);
}