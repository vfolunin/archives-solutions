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

    int opCount;
    cin >> opCount;

    double x = 0, y = 0, diag = sqrt(2) / 2;
    vector<double> dy = { 1, diag, 0, -diag, -1, -diag, 0, diag };
    vector<double> dx = { 0, diag, 1, diag, 0, -diag, -1, -diag };

    for (int i = 0; i < opCount; i++) {
        int d, step;
        cin >> d >> step;
        d--;
        y += dy[d] * step;
        x += dx[d] * step;
    }

    cout << fixed << x << " " << y;
}