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

    double a, b, c;
    cin >> a >> b >> c;

    cout.precision(1);
    cout << "MEDIA = " << fixed << (a * 2 + b * 3 + c * 5) / 10 << "\n";
}