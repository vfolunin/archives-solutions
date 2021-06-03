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

    map<string, string> accountName;
    while (1) {
        char numBuf[4], nameBuf[100];
        scanf("%3s%[^\n]", numBuf, nameBuf);
        string num = numBuf, name = nameBuf;

        if (num == "000")
            break;

        accountName[num] = name;
    }

    map<string, long long> total;
    map<string, vector<pair<string, long long>>> ops;
    while (1) {
        char tBuf[4], numBuf[4];
        long long delta;
        scanf("%3s%3s%lld", tBuf, numBuf, &delta);
        string t = tBuf, num = numBuf;

        if (t == "000")
            break;

        total[t] += delta;
        ops[t].push_back({ num, delta });
    }

    for (auto &[t, res] : total) {
        if (res) {
            printf("*** Transaction %s is out of balance ***\n", t.c_str());
            for (auto &[num, delta] : ops[t])
                printf("%s %-30s %10.2lf\n", num.c_str(), accountName[num].c_str(), delta / 100.0);
            printf("999 %-30s %10.2lf\n\n", "Out of Balance", -res / 100.0);
        }
    }
}