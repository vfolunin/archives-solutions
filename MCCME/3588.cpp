#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<long long> tSum;
    vector<int> tMin;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            tSum[v] = tMin[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        tSum[v] = tSum[2 * v + 1] + tSum[2 * v + 2];
        tMin[v] = min(tMin[2 * v + 1], tMin[2 * v + 2]);
    }

    pair<long long, int> query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return { 0, 1e9 };
        if (l <= vl && vr <= r)
            return { tSum[v], tMin[v] };
        int vm = vl + (vr - vl) / 2;
        auto [lSum, lMin] = query(2 * v + 1, vl, vm, l, r);
        auto [rSum, rMin] = query(2 * v + 2, vm + 1, vr, l, r);
        return { lSum + rSum, min(lMin, rMin) };
    }

    SegmentTree(vector<int> &a) :
        size(a.size()), tSum(4 * a.size()), tMin(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    long long get(int l, int r) {
        auto [sum, min] = query(0, 0, size - 1, l, r);
        return sum * min;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size, width;
    cin >> size >> width;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    SegmentTree segmentTree(a);

    vector<long long> maxCost(size + 1);
    vector<int> from(size + 1, -1);
    for (int i = width; i <= size; i++) {
        maxCost[i] = maxCost[i - 1];
        long long segmentCost = segmentTree.get(i - width, i - 1);
        if (maxCost[i] < maxCost[i - width] + segmentCost) {
            maxCost[i] = maxCost[i - width] + segmentCost;
            from[i] = i - width + 1;
        }
    }

    vector<int> path;
    for (int i = size; i; ) {
        if (from[i] == -1) {
            i--;
        } else {
            path.push_back(from[i]);
            i = from[i] - 1;
        }
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int value : path)
        cout << value << " ";
}