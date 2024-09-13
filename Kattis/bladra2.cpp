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

    double v, a, t;
    cin >> v >> a >> t;

    cout << fixed << v * t + a * t * t / 2;
}