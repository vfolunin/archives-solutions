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

    double r;
    cin >> r;

    const double PI = 3.14159;

    cout.precision(3);
    cout << "VOLUME = " << fixed << PI * r * r * r * 4 / 3 << "\n";
}