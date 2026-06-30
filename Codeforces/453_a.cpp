#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int faceCount, rollCount;
    cin >> faceCount >> rollCount;

    double res = faceCount;
    for (int i = 1; i < faceCount; i++)
        res -= pow((double)i / faceCount, rollCount);

    cout << fixed << res;
}