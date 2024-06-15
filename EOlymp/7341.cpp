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

    int hLimit, wLimit;
    cin >> hLimit >> wLimit;

    long long res = 0;
    for (int h = 1; h <= hLimit; h++)
        for (int w = 1; w <= wLimit; w++)
            res += (hLimit - h + 1LL) * (wLimit - w + 1);
    
    cout << res;
}