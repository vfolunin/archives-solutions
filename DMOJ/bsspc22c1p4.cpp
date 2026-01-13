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

    int size, limit;
    cin >> size >> limit;

    int sum = 0, maxValue = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        maxValue = max(maxValue, value);

        if (sum - maxValue <= limit)
            res++;
        else
            break;
    }
    res -= res > 0;

    cout << res;
}