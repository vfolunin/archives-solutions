#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = 1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res = lcm(res, value + 1);
    }

    cout << res - 1;
}