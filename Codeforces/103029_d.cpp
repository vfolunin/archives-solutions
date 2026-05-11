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

    long long h, w;
    cin >> h >> w;

    long long a = (w * 2 - 1) * (long long)(h / (sqrt(3) / 2));
    long long b = (h * 2 - 1) * (long long)(w / (sqrt(3) / 2));

    cout << max(a, b);
}