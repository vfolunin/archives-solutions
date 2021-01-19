#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n, countLimit, weightLimit;
    cin >> n >> countLimit >> weightLimit;

    vector<int> weight(n);
    for (int &x : weight)
        cin >> x;

    int eggsCount = 0, eggsWeight = 0;
    for (int i = 0; i < n; i++) {
        if (eggsCount + 1 <= countLimit && eggsWeight + weight[i] <= weightLimit) {
            eggsCount++;
            eggsWeight += weight[i];
        }
    }

    cout << "Case " << test << ": " << eggsCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}