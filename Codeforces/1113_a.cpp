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

    int cityCount, capacity;
    cin >> cityCount >> capacity;

    int volume = min(cityCount - 1, capacity), res = volume;
    for (int city = 2; city <= cityCount; city++) {
        volume--;
        if (city + volume < cityCount) {
            volume++;
            res += city;
        }
    }

    cout << res;
}