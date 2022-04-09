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

    int machineCount, itemCount;
    cin >> machineCount >> itemCount;

    long long sumTime = 0, maxTime = 0;
    for (int i = 0; i < machineCount; i++) {
        int time;
        cin >> time;
        sumTime += time;
        maxTime = max<long long>(maxTime, time);
    }

    cout << sumTime + maxTime * (itemCount - 1);
}