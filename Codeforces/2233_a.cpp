#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int linesNeeded, aSpeed, bSpeed, bPrepTime;
    cin >> linesNeeded >> aSpeed >> bSpeed >> bPrepTime;

    int time1 = (linesNeeded + aSpeed + bSpeed - 1) / (aSpeed + bSpeed);

    linesNeeded = max(0, linesNeeded - aSpeed * bPrepTime);
    bSpeed *= 10;
    int time2 = bPrepTime + (linesNeeded + aSpeed + bSpeed - 1) / (aSpeed + bSpeed);
    
    cout << min(time1, time2) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}