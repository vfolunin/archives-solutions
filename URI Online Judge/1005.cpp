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

    double a, b;
    cin >> a >> b;

    cout.precision(5);
    cout << "MEDIA = " << fixed << (a * 3.5 + b * 7.5) / 11 << "\n";
}