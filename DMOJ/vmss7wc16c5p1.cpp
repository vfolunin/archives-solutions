#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int length, int downloadTime, int time) {
    for (int i = 0; i < length; i++) {
        time++;
        if (time < downloadTime)
            return 0;
        time -= downloadTime;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int length, downloadTime;
    cin >> length >> downloadTime;

    int l = -1, r = 1;
    while (!can(length, downloadTime, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(length, downloadTime, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}