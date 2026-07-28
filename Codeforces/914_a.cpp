#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isSquare(int value) {
    if (value < 0)
        return 0;
    int root = sqrt(value);
    return root * root == value;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = -2e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!isSquare(value))
            res = max(res, value);
    }

    cout << res;
}