#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BIT {
    vector<int> f;

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }

    BIT(int size) : f(size) {}
};

void access(vector<int> &cacheSize, vector<int> &missCount, vector<int> &lastTime, int &curTime, BIT &bit, int val) {
    if (lastTime[val] == -1) {
        for (int i = 0; i < missCount.size(); i++)
            missCount[i]++;
    } else {
        int elemCount = bit.sum(lastTime[val], curTime);
        for (int i = 0; i < missCount.size(); i++)
            missCount[i] += cacheSize[i] < elemCount;
        bit.add(lastTime[val], -1);
    }
    bit.add(curTime, 1);
    lastTime[val] = curTime++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cacheCount;
    cin >> cacheCount;

    vector<int> cacheSize(cacheCount);
    for (int &size : cacheSize)
        cin >> size;

    vector<int> missCount(cacheCount);
    vector<int> lastTime(1 << 24, -1);
    int curTime = 0;
    BIT bit(1e7);

    while (1) {
        string op;
        cin >> op;

        if (op == "ADDR") {
            int val;
            cin >> val;
            access(cacheSize, missCount, lastTime, curTime, bit, val);

        } else if (op == "RANGE") {
            int b, a, n;
            cin >> b >> a >> n;
            for (int k = 0; k < n; k++)
                access(cacheSize, missCount, lastTime, curTime, bit, a * k + b);

        } else if (op == "STAT") {
            for (int i = 0; i < cacheCount; i++)
                cout << missCount[i] << (i + 1 < cacheCount ? " " : "\n");
            missCount.assign(cacheCount, 0);

        } else {
            break;
        }
    }
}