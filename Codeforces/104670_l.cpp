#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cicadaCount;
    cin >> cicadaCount;

    int minYear = 1e9;

    for (int i = 0; i < cicadaCount; i++) {
        int year, a, b;
        cin >> year >> a >> b;
        minYear = min(minYear, year + lcm(a, b));
    }

    cout << minYear;
}