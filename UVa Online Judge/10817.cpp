#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPowersOf3() {
    vector<int> p = { 1 };
    for (int i = 1; i < 9; i++)
        p.push_back(p[i - 1] * 3);
    return p;
}

int readMask() {
    static vector<int> p = getPowersOf3();
    int mask = 0;

    while (cin.peek() == ' ') {
        int bit;
        cin >> bit;
        bit--;

        if (mask / p[bit] % 3 != 2)
            mask += p[bit];
    }

    return mask;
}

int addMasks(int maskA, int maskB) {
    static vector<int> p = getPowersOf3();
    int mask = 0;

    for (int bit = 0; bit < 8; bit++) {
        int a = maskA / p[bit] % 3;
        int b = maskB / p[bit] % 3;
        mask += p[bit] * min(a + b, 2);
    }

    return mask;
}

bool solve() {
    int subjectCount, employeeCount, applicantCount;
    cin >> subjectCount >> employeeCount >> applicantCount;

    if (!subjectCount)
        return 0;

    int initCost = 0, initMask = 0;

    for (int i = 0; i < employeeCount; i++) {
        int curCost;
        cin >> curCost;
        initCost += curCost;

        int curMask = readMask();
        initMask = addMasks(initMask, curMask);
    }

    static vector<int> p = getPowersOf3();
    vector<int> cost(p[subjectCount], 1e9);
    cost[initMask] = initCost;

    for (int i = 0; i < applicantCount; i++) {
        int curCost;
        cin >> curCost;

        int curMask = readMask();
        for (int mask = cost.size() - 1; mask >= 0; mask--) {
            int m = addMasks(mask, curMask);
            cost[m] = min(cost[m], cost[mask] + curCost);
        }
    }

    cout << cost.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}