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

    int size;
    cin >> size;

    int sum1 = 0, sum2 = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            if (y == x)
                sum1 += value;
            if (y + x == size - 1)
                sum2 += value;
        }
    }

    cout << sum1 << " " << sum2;
}