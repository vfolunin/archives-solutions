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

    int a, b;
    cin >> a >> b;

    int t = 24 - a + b;

    if (20 <= a && a <= 23 && 6 <= b && b <= 9 && 8 <= t && t <= 10)
        cout << "Healthy\n";
    else
        cout << "Unhealthy\n";
}