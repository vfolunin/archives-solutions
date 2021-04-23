#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(vector<int> &pairWeight, vector<int> &weight) {
    vector<int> res;
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            res.push_back(weight[i] + weight[j]);
    sort(res.begin(), res.end());
    return res == pairWeight;
}

void solve(int test) {
    vector<int> pairWeight(10);
    for (int &w : pairWeight)
        cin >> w;

    vector<int> weight(5);
    for (weight[0] = 1; weight[0] * 2 <= pairWeight[0]; weight[0]++) {
        weight[1] = pairWeight[0] - weight[0];
        weight[2] = pairWeight[1] - weight[0];
        weight[4] = pairWeight[8] - weight[2];
        weight[3] = pairWeight[9] - weight[4];
        if (check(pairWeight, weight))
            break;
    }

    cout << "Case " << test << ": ";
    for (int i = 0; i < 5; i++)
        cout << weight[i] << (i < 4 ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}