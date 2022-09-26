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
 
    int n;
    cin >> n;

    int zeroCount = 0, positiveCount = 0, negativeCount = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        zeroCount += !value;
        positiveCount += value > 0;
        negativeCount += value < 0;
    }

    cout << zeroCount << " " << positiveCount << " " << negativeCount;
}