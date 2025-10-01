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

    vector<int> sum(2);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            if (y > x)
                sum[0] += value;
            else if (y < x)
                sum[1] += value;
        }
    }

    if (sum[0] < sum[1])
        cout << "UPPER";
    else if (sum[0] == sum[1])
        cout << "EQUAL";
    else
        cout << "LOWER";
}