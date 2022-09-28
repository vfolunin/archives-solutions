#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double squareSum = 0, sum = 0, count = 0;

    while (1) {
        double value;
        cin >> value;

        if (!value)
            break;

        squareSum += value * value;
        sum += value;
        count++;
    }

    double mean = sum / count;
    double stddev2 = (squareSum - 2 * sum * mean + count * mean * mean) / (count - 1);

    cout << fixed << sqrt(stddev2);
}