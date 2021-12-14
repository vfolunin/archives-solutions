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

    int pinCount, targetHeight;
    cin >> pinCount >> targetHeight;

    vector<int> height(pinCount);
    for (int &h : height)
        cin >> h;

    int res = 0;
    for (int i = 0; i + 1 < pinCount; i++) {
        if (height[i] > targetHeight) {
            res += height[i] - targetHeight;
            height[i + 1] -= height[i] - targetHeight;
        } else if (height[i] < targetHeight) {
            res += targetHeight - height[i];
            height[i + 1] += targetHeight - height[i];
        }
    }

    cout << res << "\n";
}