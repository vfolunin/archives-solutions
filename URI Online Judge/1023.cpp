#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int fractionCount;
    cin >> fractionCount;

    if (!fractionCount)
        return 0;

    double totalNum = 0, totalDen = 0;
    map<int, int> ratios;

    for (int i = 0; i < fractionCount; i++) {
        int num, den;
        cin >> den >> num;

        totalNum += num;
        totalDen += den;
        ratios[num / den] += den;
    }

    if (test > 1)
        cout << "\n";
    cout << "Cidade# " << test << ":\n";
    for (auto it = ratios.begin(); it != ratios.end(); it++)
        cout << it->second << "-" << it->first << (next(it) != ratios.end() ? " " : "\n");
    cout.precision(2);
    cout << "Consumo medio: " << fixed << floor(totalNum / totalDen * 100) / 100 << " m3.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}