#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int size, double h0, double h1) {
    for (int i = 2; i < size; i++) {
        double h2 = 2 * h1 + 2 - h0;
        if (h2 < 1e-6)
            return 0;
        h0 = h1;
        h1 = h2;
    }
    return 1;
}

double getHLast(int size, double h0, double h1) {
    for (int i = 2; i < size; i++) {
        double h2 = 2 * h1 + 2 - h0;
        h0 = h1;
        h1 = h2;
    }
    return h1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    double h0;
    cin >> size >> h0;

    double l = 0, r = h0;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(size, h0, m))
            r = m;
        else
            l = m;
    }

    cout << fixed << getHLast(size, h0, l);
}