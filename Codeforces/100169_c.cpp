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

    int canCount, colorCount;
    cin >> canCount >> colorCount;

    vector<int> cans(canCount);
    for (int &can : cans)
        cin >> can;

    sort(cans.begin(), cans.end());

    long long res = 0;
    for (int i = 0; i < colorCount; i++) {
        int canNeeded;
        cin >> canNeeded;
        res += *lower_bound(cans.begin(), cans.end(), canNeeded) - canNeeded;
    }

    cout << res;
}