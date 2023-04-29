#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getMaxTime(vector<long long> &cardTime, long long sum) {
    long long res = 0;
    for (int i = cardTime.size() - 1; i >= 0; i--)
        if (sum & (1LL << i))
            res += cardTime[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long time;
    cin >> time;

    vector<long long> cardTime(31);
    for (long long &time : cardTime)
        cin >> time;

    for (int i = 1; i < cardTime.size(); i++)
        cardTime[i] = max(cardTime[i], 2 * cardTime[i - 1]);

    long long l = 0, r = (1LL << 32) - 1;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (getMaxTime(cardTime, m) >= time)
            r = m;
        else
            l = m;
    }

    cout << r;
}