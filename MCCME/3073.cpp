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

    int prevValue = 1e9, sum = 0;

    while (1) {
        int value;
        cin >> value;

        if (!prevValue && !value)
            break;

        sum += value;
        prevValue = value;
    }

    cout << sum;
}