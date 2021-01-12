#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double riverWidth, riverSpeed, boatSpeed;
    cin >> riverWidth >> riverSpeed >> boatSpeed;

    cout << "Case " << test << ": ";

    if (riverSpeed == 0 || riverSpeed >= boatSpeed) {
        cout << "can't determine\n";
        return;
    }

    double time1 = riverWidth / boatSpeed;
    double boatSpeed2 = sqrt(boatSpeed * boatSpeed - riverSpeed * riverSpeed);
    double time2 = riverWidth / boatSpeed2;

    cout.precision(3);
    cout << fixed << time2 - time1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}