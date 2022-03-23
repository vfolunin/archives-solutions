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

    int companyCount;
    cin >> companyCount;

    map<int, map<int, int>> dayShares;
    for (int company = 0; company < companyCount; company++) {
        int recordCount;
        cin >> recordCount;
        for (int j = 0; j < recordCount; j++) {
            int shareCount, day;
            cin >> shareCount >> day;
            dayShares[day][company] = shareCount;
        }
    }

    map<int, int> shares;
    int totalShareCount = 0;

    for (auto &[day, companyShareCount] : dayShares) {
        for (auto &[company, shareCount] : companyShareCount) {
            totalShareCount -= shares[company];
            shares[company] = shareCount;
            totalShareCount += shares[company];
        }
        cout << totalShareCount << " ";
    }
}