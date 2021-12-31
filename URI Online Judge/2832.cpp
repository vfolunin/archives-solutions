#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &capsules, int targetCoinCount, long long t) {
    long long coinCount = 0;
    for (int &capsule : capsules)
        coinCount += t / capsule;
    return coinCount >= targetCoinCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int capsuleCount, targetCoinCount;
    cin >> capsuleCount >> targetCoinCount;

    vector<int> capsules(capsuleCount);
    for (int &capsule : capsules)
        cin >> capsule;

    long long l = 0, r = 1e18;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(capsules, targetCoinCount, m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
}