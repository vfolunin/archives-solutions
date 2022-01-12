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

    int judgeCount, rateCount;
    cin >> judgeCount >> rateCount;

    double rateSum = 0;
    for (int i = 0; i < rateCount; i++) {
        int rate;
        cin >> rate;
        rateSum += rate;
    }

    cout << fixed << (rateSum - 3 * (judgeCount - rateCount)) / judgeCount << " ";
    cout << fixed << (rateSum + 3 * (judgeCount - rateCount)) / judgeCount << "\n";
}