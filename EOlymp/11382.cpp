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

    int h, m, delta;
    cin >> h >> m >> delta;

    int t = (h * 60 + m - delta + 1440) % 1440;

    cout << t / 60 << " " << t % 60;
}