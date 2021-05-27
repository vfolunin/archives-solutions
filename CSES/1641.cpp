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

    int n, targetSum;
    cin >> n >> targetSum;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back({ x, i });
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        for (int l = i + 1, r = n - 1; l < r; ) {
            while (l < r && arr[i].first + arr[l].first + arr[r].first < targetSum)
                l++;
            while (l < r && arr[i].first + arr[l].first + arr[r].first > targetSum)
                r--;
            if (l < r && arr[i].first + arr[l].first + arr[r].first == targetSum) {
                cout << arr[i].second + 1 << " " << arr[l].second + 1 << " " << arr[r].second + 1;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}