#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, long long> sum;
    long long res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum[value - i] += value;
        res = max(res, sum[value - i]);
    }

    cout << res;
}