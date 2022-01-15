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

    int numberCount;
    cin >> numberCount;

    int negativeSum = 0;
    for (int i = 0; i < numberCount; i++) {
        int number;
        cin >> number;
        if (number < 0)
            negativeSum += number;
    }

    cout << -negativeSum;
}