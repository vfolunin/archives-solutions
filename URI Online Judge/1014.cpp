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

    double dist, fuel;
    cin >> dist >> fuel;

    cout.precision(3);
    cout << fixed << dist / fuel << " km/l" << "\n";
}