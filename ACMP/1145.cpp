#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a;
    double sum = 0;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
        sum += value;
    }

    sum /= a.size();

    double stdDev = 0;
    for (int &value : a)
        stdDev += (value - sum) * (value - sum);
    stdDev = sqrt(stdDev / (a.size() - 1));

    cout << fixed << stdDev;
}