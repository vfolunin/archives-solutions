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

    int orderCount, capacity;
    cin >> orderCount >> capacity;

    int volume = capacity, refillCount = 0;
    for (int i = 0; i < orderCount; i++) {
        string order;
        cin >> order;

        int orderVolume = order[0] - '0' + (order.size() == 2);
        if (volume < orderVolume) {
            volume = capacity;
            refillCount++;
        }
        volume -= orderVolume;
    }

    cout << refillCount;
}