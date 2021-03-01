#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    cin >> line;

    vector<int> height = { 0 };
    int curHeight = 0;
    for (char c : line) {
        if (c == '/')
            curHeight++;
        if (c == '\\')
            curHeight--;
        height.push_back(curHeight);
    }

    int minHeight = *min_element(height.begin(), height.end());
    for (int &h : height)
        h -= minHeight;

    vector<int> maxHeightL = height;
    for (int i = 1; i < height.size(); i++)
        maxHeightL[i] = max(maxHeightL[i - 1], height[i]);

    vector<int> maxHeightR = height;
    for (int i = height.size() - 2; i >= 0; i--)
        maxHeightR[i] = max(maxHeightR[i + 1], height[i]);

    int res = 0;
    for (int i = 0; i < height.size(); i++) {
        int border = min(maxHeightL[i], maxHeightR[i]);
        res += max(0, border - height[i]);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}