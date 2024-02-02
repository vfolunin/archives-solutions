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

    for (double x; cin >> x; )
        cout << fixed << sin(x) + sqrt(log(3 * x) / log(4)) + ceil(3 * exp(x)) << "\n";
}