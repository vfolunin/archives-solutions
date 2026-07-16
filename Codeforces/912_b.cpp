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

    long long maxValue, count;
    cin >> maxValue >> count;

    if (count == 1) {
        cout << maxValue;
    } else {
        int bit = 60;
        while (!(maxValue & (1LL << bit)))
            bit--;

        cout << (1LL << (bit + 1)) - 1;
    }
}