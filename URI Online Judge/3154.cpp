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

    double dayCount, guestCount;
    cin >> dayCount >> guestCount;

    double p = 1;
    for (int i = 0; i < guestCount; i++)
        p *= (dayCount - i) / dayCount;

    cout.precision(2);
    cout << fixed << (1 - p) * 100 << "\n";
}