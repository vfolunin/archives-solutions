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

    double time, speed;
    cin >> time >> speed;

    cout.precision(3);
    cout << fixed << time * speed / 12 << "\n";
}