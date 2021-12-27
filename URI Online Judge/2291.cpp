#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> divisorSum(1e6 + 1);

    for (int d = 1; d < divisorSum.size(); d++)
        for (int i = d; i < divisorSum.size(); i += d)
            divisorSum[i] += d;

    for (int i = 2; i < divisorSum.size(); i++)
        divisorSum[i] += divisorSum[i - 1];

    return divisorSum;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> divisorSum = prepare();

    cout << divisorSum[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}