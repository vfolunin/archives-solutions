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

    int a, b, c, volume, itemCount;
    cin >> a >> b >> c >> volume >> itemCount;

    int totalVolume = volume;
    for (int i = 0; i < itemCount; i++) {
        int itemVolume;
        cin >> itemVolume;
        totalVolume += itemVolume;
    }

    cout << clamp(totalVolume - a * b * c, 0, volume);
}