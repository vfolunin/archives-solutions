#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = 3.1415;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double radius, volume;
    cin >> radius >> volume;

    double balloonVolume = PI * pow(radius, 3) * 4 / 3;
    int balloonCount = floor(volume / balloonVolume);

    cout << balloonCount << "\n";
}