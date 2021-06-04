#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Pair {
    long long sum;
    int i1, i2;

    bool operator < (const Pair &that) const {
        return sum < that.sum; 
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    long long targetSum;
    cin >> size >> targetSum;

    vector<long long> a(size);
    for (long long &x : a)
        cin >> x;

    vector<Pair> pairs;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            pairs.push_back({ a[i] + a[j], i, j });
    sort(pairs.begin(), pairs.end());

    for (int l = 0, r = pairs.size() - 1; l < r; l++) {
        while (l < r && pairs[l].sum + pairs[r].sum > targetSum)
            r--;
        if (l < r && pairs[l].sum + pairs[r].sum == targetSum &&
            pairs[l].i1 != pairs[r].i1 && pairs[l].i1 != pairs[r].i2 &&
            pairs[l].i2 != pairs[r].i1 && pairs[l].i2 != pairs[r].i2) {
            cout << pairs[l].i1 + 1 << " " << pairs[l].i2 + 1 << " " << pairs[r].i1 + 1 << " " << pairs[r].i2 + 1;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}