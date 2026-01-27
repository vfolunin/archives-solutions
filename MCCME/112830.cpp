#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getTime(long long factoryPrice, long long factoryProduction, long long targetFactoryCount, long long targetMoney) {
    long long money = 0, time = 0, factoryCount = 0, production = 1;
    while (factoryCount < targetFactoryCount) {
        if (money >= factoryPrice) {
            long long deltaFactoryCount = min(money / factoryPrice, targetFactoryCount - factoryCount);
            money -= factoryPrice * deltaFactoryCount;
            factoryCount += deltaFactoryCount;
            production += factoryProduction * deltaFactoryCount;
        } else if (production <= factoryPrice) {
            long long deltaTime = (factoryPrice - money + production - 1) / production;
            money += deltaTime * production - factoryPrice;
            time += deltaTime;
            factoryCount++;
            production += factoryProduction;
        } else {
            money += production;
            time++;
        }
    }

    targetMoney = max(targetMoney - money, 0LL);
    time += (targetMoney + production - 1) / production;
    return time;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long factoryPrice, factoryProduction, targetMoney;
    cin >> factoryPrice >> factoryProduction >> targetMoney;

    long long minTime = targetMoney;
    for (long long targetFactoryCount = 0; 1; targetFactoryCount++) {
        long long time = getTime(factoryPrice, factoryProduction, targetFactoryCount, targetMoney);
        if (minTime >= time)
            minTime = time;
        else
            break;
    }

    cout << minTime;
}