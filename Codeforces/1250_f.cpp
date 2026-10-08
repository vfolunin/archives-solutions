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

    int value;
    cin >> value;

    int maxD = 1;
    for (int d = 2; d * d <= value; d++)
        if (value % d == 0)
            maxD = d;

    cout << 2 * (maxD + value / maxD);
}