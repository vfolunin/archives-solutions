#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long distance, speed1, speed2, time;
    cin >> distance >> speed1 >> speed2 >> time;

    long long coord1 = speed1 * time % distance;
    long long coord2 = speed2 * time % distance;

    long long res = abs(coord1 - coord2);
    res = min(res, distance - res);

    cout << res;
}