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

    double sum = 0;

    for (int i = 0; i < 10; i++)
        sum += 4.0 * (i % 2 ? -1 : 1) / (i * 2 + 1);

    cout.precision(10);
    cout << fixed << sum;
}