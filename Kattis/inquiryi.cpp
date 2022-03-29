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

    vector<long long> a(size);
    long long sum = 0;
    for (long long &value : a) {
        cin >> value;
        sum += value;
    }

    long long squareSum = 0, res = 0;
    for (long long value : a) {
        sum -= value;
        squareSum += value * value;
        res = max(res, squareSum * sum);
    }

    cout << res;
}