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

    double sum = 0;
    for (int i = 1; i <= 10; i++)
        sum += 1.0 / (i * i);

    cout.precision(10);
    cout << fixed << sqrt(6 * sum);
}