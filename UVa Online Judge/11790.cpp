#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int buildingCount;
    cin >> buildingCount;

    vector<int> height(buildingCount);
    for (int &x : height)
        cin >> x;

    vector<int> width(buildingCount);
    for (int &x : width)
        cin >> x;

    vector<int> lis(buildingCount), lds(buildingCount);
    for (int i = 0; i < buildingCount; i++) {
        lis[i] = lds[i] = width[i];
        for (int j = 0; j < i; j++) {
            if (height[j] < height[i])
                lis[i] = max(lis[i], lis[j] + width[i]);
            if (height[j] > height[i])
                lds[i] = max(lds[i], lds[j] + width[i]);
        }
    }

    int maxLis = *max_element(lis.begin(), lis.end());
    int maxLds = *max_element(lds.begin(), lds.end());

    cout << "Case " << test << ". ";
    if (maxLis >= maxLds)
        cout << "Increasing (" << maxLis << "). Decreasing (" << maxLds << ").\n";
    else
        cout << "Decreasing (" << maxLds << "). Increasing (" << maxLis << ").\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}