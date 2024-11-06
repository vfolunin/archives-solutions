#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void rec(vector<int> &a, int i, int sum, vector<bool> &can) {
    if (i == a.size()) {
        if (0 <= sum && sum < can.size())
            can[sum] = 1;
        return;
    }

    rec(a, i + 1, sum, can);
    rec(a, i + 1, sum + a[i], can);
    rec(a, i + 1, sum - a[i], can);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<bool> can(5e7);
    rec(a, 0, 0, can);

    int res = 0;
    while (can[res])
        res++;

    cout << res;
}