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

    int temperatureCount;
    cin >> temperatureCount;

    int negativeCount = 0;
    for (int i = 0; i < temperatureCount; i++) {
        int temperature;
        cin >> temperature;
        negativeCount += temperature < 0;
    }

    cout << negativeCount;
}