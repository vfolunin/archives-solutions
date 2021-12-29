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

    long long w, h;
    int soldierCount;
    cin >> w >> h >> soldierCount;

    vector<int> skillSum(2);
    for (int i = 0; i < soldierCount; i++) {
        int x, y, skill;
        cin >> x >> y >> skill;
        skillSum[x * h > w * y] += skill;
    }

    cout << skillSum[0] << " " << skillSum[1] << "\n";
}