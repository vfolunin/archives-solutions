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

    int h, m, s;
    string half;
    cin >> h >> m >> s >> half;

    int time = h * 3600 + m * 60 + s;
    if (h < 12 && half == "PM")
        time += 12 * 3600;

    cout << time;
}