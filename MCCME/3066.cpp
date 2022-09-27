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

    int sum = 0, count = 0;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        sum += value;
        count++;
    }

    cout << fixed << 1.0 * sum / count;
}